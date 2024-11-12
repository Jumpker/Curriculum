from mcpi.minecraft import Minecraft


def set():
    mc = Minecraft.create()
    pos = mc.player.getTilePos()
    mc.setBlock(pos.x, pos.y-1, pos.z,'GLASS')

set()
