from mcpi import minecraft

mc = minecraft.Minecraft.create()

GAP = 'AIR'
WALL = 'GOLD_BLOCK'
FLOOR = 'GRASS'
FILENAME = "maze.csv"

f = open(FILENAME, "r")
pos = mc.player.getTilePos()
ORGIN_X = pos.x + 1
ORGIN_Y = pos.y
ORGIN_Z = pos.z + 1
z = ORGIN_Z

for line in f.readlines():
    data = line.split(",")
    x = ORGIN_X
    for cell in data:
        if cell == "0":
            b = GAP
        else:
            b = WALL
        mc.setBlock(x, ORGIN_Y, z, b)
        mc.setBlock(x, ORGIN_Y + 1, z, b)
        mc.setBlock(x, ORGIN_Y - 1, z, FLOOR)
        x = x + 1
    z = z + 1
