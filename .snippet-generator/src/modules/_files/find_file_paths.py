import glob
import os
from typing import List
from modules._files.tools import trimming_end_of_slash

def find_file_paths(directory_paths: List[str]) -> List[str]:
    if not directory_paths:
      return []

    all_file_paths = []

    for directory_path in directory_paths:
        file_paths = glob.glob(directory_path + '/**', recursive=True)

        # TODO: ここにほんとに trimming は必要なのか
        file_paths = list(map(trimming_end_of_slash, file_paths))
        file_paths = list(filter(os.path.isfile, file_paths))

        for file_path in file_paths:
            all_file_paths.append(file_path)

    return all_file_paths
