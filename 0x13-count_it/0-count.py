#!/usr/bin/python3
""" reddit recursive API call """

import requests as r


HEADERS = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
            AppleWebKit/537.36 (KHTML, like Gecko)\
                 Chrome/87.0.4280.88 Safari/537.36'
           }


def recursive_call(subreddit, hot_list=[], after="nil"):
    """ get number of subs reddit """
    url = "https://www.reddit.com/r/{}.json?sort=hot&after={}&limit=100"\
        .format(subreddit, after)
    try:
        subs = r.get(url, headers=headers,
                     allow_redirects=False).json()
        data = subs.get("data")
        after = subs.get("data").get("after")
        hot_list += [story.get("data")['title'] for story in data['children']]
        if after is not None:
            recursive_call(subreddit, hot_list, after)
        return hot_list
    except Exception:
        pass


def count_words(subreddit, word_list, lista=None, word_dict={}):
    """ count words fucntion """

    if word_dict == {}:
        for word in word_list:
            word_dict.update({word: 0})
    if lista is None:
        lista = recursive_call(subreddit)
    if lista and len(lista) > 0:
        if word_list != []:
            word_list = list(set(word_list))
            for item in lista:
                item = item.lower()
                if word_list[-1].lower() in item.split():
                    if word_list[-1] in word_dict.keys():
                        word_dict[word_list[-1]] += 1
            word_list.pop(-1)
            count_words(subreddit, word_list, lista, word_dict)
        else:
            for key in sorted(word_dict.items(),
                              key=lambda kv: (-kv[1], kv[0])):
                if key[1] != 0:
                    print("{}: {}".format(key[0], key[1]))
