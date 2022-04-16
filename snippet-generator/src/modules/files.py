from typing import List

from modules._files.find_file_paths import find_file_paths
from modules._files.tools import trimming_end_of_slash

def find_files(directory_paths: List[str]) -> List[str]:
    directory_paths = list(map(trimming_end_of_slash, directory_paths))
    return find_file_paths(directory_paths)
