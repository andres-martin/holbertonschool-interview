#!/usr/bin/python3
""" Count it algorithm """
from requests import get

REDDIT = "https://www.reddit.com/"
HEADERS = {'user-agent': 'my-app/0.0.1'}


def count_words(reddit, hot_list, after_word="", dic={}):
    """ self descriptive function """
    if not dic:
        for word in hot_list:
            dic[word] = 0

    if not after_word:
        hot_list = [[key, value] for key, value in dic.items()]
        hot_list = sorted(hot_list, key=lambda x: (-x[1], x[0]))

        for word in hot_list:
            if word[1]:
                print(f"{word[0].lower()},: {word[1]}")
        return None

    url = REDDIT + f"r/{reddit}/hot/.json"

    params = {
        'limit': 100,
        'after': after_word
    }

    res = get(url, headers=HEADERS, params=params, allow_redirects=False)

    if res.status_code != 200:
        return None

    try:
        js = res.json()

    except ValueError:
        return None

    try:

        data = js.get("data")
        after_word = data.get("after_word")
        children = data.get("children")
        for child in children:
            post = child.get("data")
            title = post.get("title")
            lower = [sm.lower() for sm in title.split(' ')]

            for word in hot_list:
                dic[word] += lower.count(word.lower())

    except Exception:
        return None

    count_words(reddit, hot_list, after_word, dic)
