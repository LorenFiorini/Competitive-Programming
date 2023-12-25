
''' 
# 1st attempt: 0/100 points

# Find minimum and maximum X-coordinates
minX = int(1e15)
maxX = 0
# Find minimum and maximum Y-coordinates
minY = int(1e15)
maxY = 0

def min_square_side(N, K, X, Y):
    global minX, maxX, minY, maxY
    # Handle special case: all points at same coordinates
    if minX == maxX or minY == maxY:
        side_length = 0
    return min(maxX - minX, maxY - minY)

def solve():
    global minX, maxX, minY, maxY
    N, K = map(int, input().split())
    X = []
    Y = []
    for _ in range(N):
        x, y = map(int, input().split())
        minX = min(minX, x)
        maxX = max(maxX, x)
        minY = min(minY, y)
        maxY = max(maxY, y)
        X.append(x)
        Y.append(y)
    side_length = min_square_side(N, K, X, Y)
    print(side_length)

solve()
'''

"""
# 2nd attempt: 0/100 points
def main():
    n, k = map(int, input().split())
    points = []
    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))
    # Sort the points by x-coordinate
    points.sort(key=lambda p: p[0])
    # Find the minimum and maximum x-coordinates
    min_x, max_x = points[0][0], points[-1][0]
    # Sort the points by y-coordinate
    points.sort(key=lambda p: p[1])
    # Find the minimum and maximum y-coordinates
    min_y, max_y = points[0][1], points[-1][1]
    # Calculate the minimum side length
    side_length = max(max_x - min_x + 1, max_y - min_y + 1)
    print(side_length // 2)

if __name__ == "__main__":
    main()

# 892924467
# 892924466
"""

# 3rd attempt: 100/100 points

def solve(N, K, points):
    min_side_length = float('inf')
    for i in range(N):
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                new_points = []
                for j in range(N):
                    if j == i:
                        new_points.append((points[j][0] + dx, points[j][1] + dy))
                    else:
                        new_points.append(points[j])
                min_side_length = min(min_side_length, min_side_length_for_points(new_points))
    return min_side_length

def min_side_length_for_points(points):
    min_x = min(point[0] for point in points)
    max_x = max(point[0] for point in points)
    min_y = min(point[1] for point in points)
    max_y = max(point[1] for point in points)
    side_length = max(max_x - min_x + 1, max_y - min_y + 1)
    return side_length

if __name__ == '__main__':
    N, K = map(int, input().split())
    points = []
    for _ in range(N):
        x, y = map(int, input().split())
        points.append([x, y])
    min_side_length = solve(N, K, points)
    print(min_side_length)
