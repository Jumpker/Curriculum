from mcpi.minecraft import Minecraft
import time

mc = Minecraft.create()

# 在mc中创建棋盘
def create_chessboard(Size):
    player_pos = mc.player.getTilePos()
    # 创建棋盘主体（黑白格子用不同方块区分）
    for x in range(Size):
        for y_board in range(Size):  # 避免与y坐标变量冲突，改用y_board
            if (x + y_board) % 2 == 0:
                mc.setBlock(player_pos.x + x, player_pos.y - 1, player_pos.z + y_board, 'WHITE_WOOL')
            else:
                mc.setBlock(player_pos.x + x, player_pos.y - 1, player_pos.z + y_board, 'BLACK_WOOL')

    # 添加玻璃边框（棋盘周围一圈, 好看一点）
    for x in [-1, Size]:  # 先左再右两侧边框
        for z in range(Size):
            mc.setBlock(player_pos.x + x, player_pos.y - 1, player_pos.z + z, 'GLASS')
    for z in [-1, Size]:  # 先前再后两侧边框
        for x in range(Size):
            mc.setBlock(player_pos.x + x, player_pos.y - 1, player_pos.z + z, 'GLASS')
    mc.postToChat("棋盘已生成，请输入初始位置")


# 计算下一步的下一步有多少种可能（启发式算法使用）
def calculateNextSteps(Board, Size, x, y, mv):
    # 数组每个单元里存储下一步的下一步有多少种可能
    # 因为下一步有8种可能所以数组长度为8
    next_steps = [0] * 8
    for i in range(8):
        # nx, ny 为下一步的位置
        nx = x + mv[i][0]
        ny = y + mv[i][1]
        # 下一步在棋盘中并且没走过
        if 0 <= nx < Size and 0 <= ny < Size and Board[nx][ny] == 0:
            next_steps[i] = 0
            for j in range(8):
                nnx = nx + mv[j][0]
                nny = ny + mv[j][1]
                if 0 <= nnx < Size and 0 <= nny < Size and Board[nnx][nny] == 0:
                    next_steps[i] += 1
        else:
            next_steps[i] = -1
    return next_steps

# 对下一步的落脚点进行排序（启发式算法使用）
def sortDirections(next_steps):
    indices = list(range(8))
    for i in range(8):
        for j in range(i + 1, 8):
            if next_steps[indices[i]] > next_steps[indices[j]]:
                indices[i], indices[j] = indices[j], indices[i]
    return indices



def DFS(Board, Size, x, y, step, player_pos):
    mv = [(2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]

    if step == Size * Size:
        Board[x][y] = step
        # 最终位置用金块标记（属于已有步骤）
        mc.setBlock(player_pos.x + x, player_pos.y, player_pos.z + y, 'GOLD_BLOCK')
        return True

    Board[x][y] = step
    # 当前步骤用钻石块标记（临时标记，探索中）
    mc.setBlock(player_pos.x + x, player_pos.y, player_pos.z + y, 'DIAMOND_BLOCK')
    time.sleep(0.7)

    next_steps = calculateNextSteps(Board, Size, x, y, mv)
    indices = sortDirections(next_steps)

    for i in indices:
        if next_steps[i] == -1:
            continue
        # 在准备访问下一个格子时将当前格子设为金块
        mc.setBlock(player_pos.x + x, player_pos.y, player_pos.z + y, 'GOLD_BLOCK')
        nx = x + mv[i][0]
        ny = y + mv[i][1]
        if DFS(Board, Size, nx, ny, step + 1, player_pos):
            return True

    Board[x][y] = 0
    # 回溯时清除标记（探索失败，恢复空气块）
    mc.setBlock(player_pos.x + x, player_pos.y, player_pos.z + y, 'AIR')
    time.sleep(0.7)
    return False


def main():
    n = int(input("请输入棋盘大小："))
    Board = [[0] * n for _ in range(n)]

    create_chessboard(n)
    player_pos = mc.player.getTilePos()

    x, y = map(int, input("请输入初始位置（1,1为左上角）：").split())
    if x < 1 or x > n or y < 1 or y > n:
        print("位置无效！")
        return
    x -= 1  # 转换为0索引
    y -= 1

    # 初始位置标记（属于当前步骤，用钻石块）
    mc.setBlock(player_pos.x + x, player_pos.y, player_pos.z + y, 'DIAMOND_BLOCK')

    # 输入初始位置后，输出正在探索路径中...
    mc.postToChat("正在探索路径中...")

    result = DFS(Board, n, x, y, 1, player_pos)
    print("路径%s！", "存在" if result else "不存在")
    if result:
        mc.postToChat("路径存在！")
        mc.postToChat("路径矩阵如下：")
        for row in Board:
            line = ""
            for val in row:
                line += str(val) + "  "
            mc.postToChat(line)
    else:
        # 路径不存在时，输出路径不存在!
        mc.postToChat("路径不存在!")


if __name__ == "__main__":
    main()
