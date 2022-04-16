import codecs

from typing import List
from modules._read.bundle import bundle

def read(
  file_path: str,
  use_oj_bundle: bool
) -> List[str]:

    if use_oj_bundle:
        return bundle(file_path)

    with codecs.open(file_path, 'r', 'utf-8') as file:
        print(file_path + ' is opened')
        return file.readlines()
