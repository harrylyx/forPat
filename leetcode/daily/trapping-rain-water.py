def trap(height) -> int:
    water = 0
    stack = []
    idx = 0
    while idx < len(height):
        stack.append(idx)
        idx += 1
        while (idx < len(height) and height[idx] > height[stack[-1]]):
            top = stack.pop()
            if not stack:
                break
            h = min(height[stack[-1]], height[idx]) - height[top]
            w = idx - stack[-1] - 1
            water += h * w
    return water


if __name__ == "__main__":
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    trap(height)
