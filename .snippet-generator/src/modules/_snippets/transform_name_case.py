import sys


def to_upper_only_first(s: str) -> str:
    if not s:
        return ''
    return s[0].upper() + s[1:]


def transform_name_case(file_name_without_extension: str, prefix_name_case: str) -> str:
    if prefix_name_case == 'Snake':
        return '_'.join(file_name_without_extension.split('-'))
    elif prefix_name_case == 'Kebab':
        return file_name_without_extension
    elif prefix_name_case == 'Pascal':
        words = file_name_without_extension.split('-')
        words = list(map(to_upper_only_first, words))
        return ''.join(words)
    elif prefix_name_case == 'Camel':
        words = file_name_without_extension.split('-')
        words = list(map(to_upper_only_first, words))
        file_name_without_extension = ''.join(words)
        return file_name_without_extension[0].lower()

    return file_name_without_extension
