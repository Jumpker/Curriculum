import mcpi.minecraftstuff as minecraftstuff
from mcpi.minecraft import Minecraft

mc = Minecraft.create()
mcdrawing = minecraftstuff.MinecraftDrawing(mc)

pos = mc.player.getTilePos()
points = minecraftstuff.Points()
points.add(pos.x, pos.y, pos.z)
points.add(pos.x + 20, pos.y, pos.z)
points.add(pos.x + 10, pos.y + 20, pos.z)

mcdrawing.drawFace(points, True, 'WHITE_WOOL')