from typing import List
from modules._snippets.transform_name_case import transform_name_case
from modules._read.trimming import trimming_empty_lines
from modules.exclude import exclude
from modules.read import read


def get_file_name(file_path: str) -> str:
    return file_path.split('/')[-1]


def trimming_extension(file_name: str) -> str:
    return file_name.split('.')[0]


def make_snippets(
    prefix: str,
    exclude_lines: List[str],
    exclude_extensions: List[str],
    file_paths: List[str],
    prefix_name_case: str,
    use_oj_bundle: bool,
    scope: str
) -> object:

    result_snippets = {}

    for file_path in file_paths:
        extension = '.' + file_path.split('.')[-1]
        if extension in exclude_extensions:
            continue

        lines: List[str] = read(file_path, use_oj_bundle)
        lines = exclude(lines, exclude_lines)
        lines = trimming_empty_lines(lines)

        file_name: str = get_file_name(file_path)

        file_name_without_extension: str = trimming_extension(file_name)

        file_name_without_extension: str = transform_name_case(
            file_name_without_extension,
            prefix_name_case
        )

        snippet = {
            # prefixをつけた拡張子なしのファイルの名前 example. cpphoge-fuga
            'prefix': prefix + file_name_without_extension,
            # body
            'body': lines,
            # Template of 拡張子なしのファイルの名前 example. Template of hoge-fuga
            'description': 'Template of ' + file_name_without_extension,
            # scope example. cpp
            'scope': scope
        }

        result_snippets[file_name] = snippet

    return result_snippets
