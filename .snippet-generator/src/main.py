# coding: utf-8
import sys
import json
import codecs
from typing import List

from modules.config import Config
from modules.snippets import make_snippets
from modules.files import find_files

def main():
    print('Hello! snippet-generator.')

    CONFIG_PATH = './config.yml'

    config = Config(config_file_path=CONFIG_PATH)

    prefix: str = config.get_prefix()
    exclude_lines: List[str] = config.get_exclude_lines()
    exclude_extensions: List[str] = config.get_exclude_extensions()
    prefix_name_case: str = config.get_prefix_name_case()
    use_oj_bundle: bool = config.get_use_oj_bundle()
    scope: str = config.get_scope()
    
    file_paths = find_files(config.get_paths())

    snippets = make_snippets(
        prefix,
        exclude_lines,
        exclude_extensions,
        file_paths,
        prefix_name_case,
        use_oj_bundle,
        scope
    )

    json_indent = config.get_json_indent()

    try:
        with codecs.open('template.code-snippets.json', 'w', 'utf-8') as file:
            json.dump(snippets, file, indent=json_indent, ensure_ascii=False)
    except Exception as e:
        print(e)
        print('Can not open template.code-snippets.json')
        sys.exit(1)


if __name__ == '__main__':
    main()
