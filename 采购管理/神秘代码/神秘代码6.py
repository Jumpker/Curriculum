import mcpi.minecraftstuff as minecraftstuff
import time

from mcpi import minecraft

mc = minecraft.Minecraft.create()
horsePos = mc.player.getTilePos()
horsePos.z += 1
horsePos.y += 1

horseShape = minecraftstuff.MinecraftShape(mc, horsePos)
horseShape.setBlock(0, 0, 0, 'OAK_PLANKS')
horseShape.setBlock(-1, 0, 0, 'OAK_PLANKS')
horseShape.setBlock(1, 0, 0, 'OAK_PLANKS')
horseShape.setBlock(-1, -1, 0, 'OAK_PLANKS')
horseShape.setBlock(1, -1, 0, 'OAK_PLANKS')
horseShape.setBlock(1, 1, 0, 'OAK_PLANKS')
horseShape.setBlock(2, 1, 0, 'OAK_PLANKS')

for count in range(10):
    time.sleep(1)
    horseShape.moveBy(1, 0, 0)
horseShape.clear()
