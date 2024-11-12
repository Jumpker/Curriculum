import mcpi.minecraft as minecraft
mc = minecraft.Minecraft.create()
def buildBridge():
    pos = mc.player.getTilePos()
    b = mc.getBlock(pos.x, pos.y-1, pos.z)
    if b == 'AIR' or b == 'WATER_FLOWING' or b == 'WATER_STATIONARY':
        mc.setBlock(pos.x, pos.y-1, pos.z, 'GLASS')




while True:
    buildBridge()
