from typing import List

# trimming empty lines from the beginning of list
def trimming_empty_lines(lines: List[str]) -> List[str]:
    idx = 0
    while lines[idx] == '':
        idx += 1

    result_lines: List[str] = []
    
    for i in range(idx, len(lines)):
        result_lines.append(lines[i])

    return result_lines
