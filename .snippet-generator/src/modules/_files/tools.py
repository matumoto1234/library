def trimming_end_of_slash(path: str) -> str:
    if path[-1] == '/':
        return path[:-1]
    return path
