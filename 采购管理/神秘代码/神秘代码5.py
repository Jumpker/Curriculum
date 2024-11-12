import mcpi.block as block
import mcpi.minecraftstuff as minecraftstuff
import math

from mcpi import minecraft


def findPointOnCircle(cx, cy, radius, angle):
    x = cx + math.sin(math.radians(angle)) * radius
    y = cy + math.cos(math.radians(angle)) * radius
    x = int(round(x, 0))
    y = int(round(y, 0))
    return (x, y)


mc = minecraft.Minecraft.create()
mcdrawing = minecraftstuff.MinecraftDrawing(mc)

middle = mc.player.getTilePos()
RADIUS = 20
HEIGHT = 10
SIDES = 4

for side in range(0, SIDES):
    point1Angle = int(round((360 / SIDES) * side, 0))
    point1X, point1Z = findPointOnCircle(middle.x, middle.z, RADIUS, point1Angle)
    point2Angle = int(round((360 / SIDES) * (side + 1), 0))
    point2X, point2Z = findPointOnCircle(middle.x, middle.z, RADIUS, point2Angle)

    points = minecraftstuff.Points()
    points.add(point1X, middle.y, point1Z)
    points.add(point2X, middle.y, point2Z)
    points.add(middle.x, middle.y + HEIGHT, middle.z)

    mcdrawing.drawFace(points, True, block.SANDSTONE.id)