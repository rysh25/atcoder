from typing import List


def all_perms(elements: List[int]) -> List[int]:
    result = []
    if (len(elements)) <= 1:
        return [elements]

    for perm in all_perms(elements[1:]):
        for i in range(len(elements)):
            result.append((perm[:i]) + elements[0:1] + perm[i:])

    return result


if __name__ == "__main__":
    for p in all_perms([1, 2, 3]):
        print(p)
