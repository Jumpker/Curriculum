from mcpi.minecraft import Minecraft
mc = Minecraft.create()

def set():
    pos = mc.player.getTilePos()
    mc.setBlock(pos.x, pos.y-1, pos.z, 0)

set()

