import sys
import subprocess
from subprocess import PIPE
from modules._read.trimming import trimming_empty_lines


def bundle(
    file_path: str,
):
    args = ['oj-bundle', file_path]

    try:
        res = subprocess.run(args, stdout=PIPE, stderr=PIPE, text=True)
    except Exception as e:
        print(e)
        print('Failed file open : ' + file_path)
        sys.exit(1)

    print('Success file open : ' + file_path)

    if res.stdout == '':
        return []

    lines = res.stdout.splitlines()
    lines = trimming_empty_lines(lines)

    return lines
