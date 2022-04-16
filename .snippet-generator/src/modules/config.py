from email.policy import default
from numbers import Number
import yaml
import codecs
from typing import List

class Config:
    _config = {}
    def __init__(self, config_file_path) -> None:
        with codecs.open(config_file_path, 'r', 'utf-8') as file:
            self._config: dict = yaml.safe_load(file)

    def get_paths(self) -> List[str]:
        return self._config.get('paths', [])

    def get_prefix(self) -> str:
        return self._config.get('prefix', '')

    def get_exclude_lines(self) -> List[str]:
        return self._config.get('excludeLines', [])

    def get_exclude_extensions(self) -> List[str]:
        return self._config.get('excludeExtensions', [])

    def get_prefix_name_case(self) -> str:
        return self._config.get('prefixNameCase', '')

    def get_json_indent(self) -> int:
        return self._config.get('jsonIndent', 2)

    def get_use_oj_bundle(self) -> bool:
        return self._config.get('useOjBundle', False)

    def get_scope(self) -> str:
        return self._config.get('scope', '')
