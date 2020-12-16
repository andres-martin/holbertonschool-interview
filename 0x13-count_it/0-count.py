#!/usr/bin/python3
""" count words function
"""

import requests


def count_words(subreddit, word_list):
    """ parses the title of all hot articles,
        and prints a sorted count of given keywords
    """
    headers = {"User-Agent": ""}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    data = requests.get(url, headers=headers, allow_redirects=False).json()
    print(data)
