def solution(sizes):
    answer = 0
    width, height = (0, 0)
    for size in sizes:
        w, h = size
        if h > w:
            w, h = h, w
        if width < w:
            width = w
        if height < h:
            height = h
    answer = width * height
    return answer