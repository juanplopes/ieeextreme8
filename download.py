#!/usr/bin/env python2
from collections import defaultdict
from getpass import getpass
import requests

PREFIX = 'https://ieee.hackerrank.com/rest/contests/ieeextreme8'
USER='LocosPorTequila'
PASS=getpass('Insert password here: ')

EXT = {'python': 'py'}

def get(url):
    r = requests.get(PREFIX+url, auth=(USER, PASS))
    return r.json()

def get_pdf(url):
    r = requests.get(PREFIX+url)
    return r.iter_content()
    
def download_challenges():
    print 'downloading challenge index'

    challenges = get('/challenges?limit=1000')['models']
    for i, challenge in enumerate(challenges):
        slug = challenge['slug']
        pdf = '/challenges/{}/download_pdf?language=English'.format(slug)
        filename = '{:02d}-{}.pdf'.format(i+1, slug)

        print 'downloading', filename
        with open(filename, 'wb') as f:
            for chunk in get_pdf(pdf):
                f.write(chunk)
 
def download_submissions():
    print 'caching challenges'
    challenges = get('/challenges?limit=1000')['models']
    ids = {c['slug']: i+1 for i, c in enumerate(challenges)}

    print 'downloading submission index'
    submissions = get('/submissions?limit=1000')['models']
    
    best = defaultdict(lambda: (0, None))
    for submission in submissions:
        slug = submission['challenge']['slug']
        sid = submission['id']
        best[slug] = max(best[slug], (submission['score'], sid))

    for slug, (score, sid) in sorted(best.items(), key=lambda x:ids.get(x[0])):
        if sid is None: continue
        cid = ids[slug]
        
        print 'downloading solution for', slug, 'id', sid, 'score=', score

        submission = get('/submissions/{}'.format(sid))['model']
        lang = submission['language']
        score = submission['score']
        filename = '{:02d}-{}.{}'.format(cid, slug, EXT.get(lang, lang))
        print 'downloaded', sid, 'as', filename
        with open(filename, 'w') as f:
            f.write(submission['code'])

download_submissions()
download_challenges()

