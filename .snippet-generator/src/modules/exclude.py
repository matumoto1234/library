from typing import List
import re

def exclude(lines: List[str], exclude_lines: List[str]) -> List[str]:
    result = []

    for line in lines:
        needs_exclude = False
        for exclude_line in exclude_lines:
            if re.match(exclude_line, line):
                needs_exclude = True
                break

        if needs_exclude:
            continue

        result.append(line)

    return result
