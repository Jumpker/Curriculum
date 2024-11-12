import mcpi.block as block
import mcpi.minecraftstuff as minecraftstuff
import time
import datetime
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
pos = mc.player.getTilePos()
clockMiddle = pos
clockMiddle.y = clockMiddle.y + 25
CLOCK_RADIUS = 20
HOUR_HAND_LENGTH = 10
MIN_HAND_LENGTH = 18
SEC_HAND_LENGTH = 20
mcdrawing.drawCircle(clockMiddle.x, clockMiddle.y, clockMiddle.z, CLOCK_RADIUS, 'DIAMOND_BLOCK')

while True:
    timeNow = datetime.datetime.now()
    hours = timeNow.hour
    if hours >= 12:
        hours = timeNow.hour - 12
    minutes = timeNow.minute
    seconds = timeNow.second

    hourHandAngle = (360 / 12) * hours + (360 / 60) * (minutes // 12)
    hourHandX, hourHandY = findPointOnCircle(clockMiddle.x, clockMiddle.y, HOUR_HAND_LENGTH, hourHandAngle)
    mcdrawing.drawLine(clockMiddle.x, clockMiddle.y, clockMiddle.z, hourHandX, hourHandY, clockMiddle.z, 'DIRT')

    minHandAngle = (360 / 60) * minutes
    minHandX, minHandY = findPointOnCircle(clockMiddle.x, clockMiddle.y, MIN_HAND_LENGTH, minHandAngle)
    mcdrawing.drawLine(clockMiddle.x, clockMiddle.y, clockMiddle.z - 1, minHandX, minHandY, clockMiddle.z - 1,'OAK_PLANKS')

    secHandAngle = (360 / 60) * seconds
    secHandX, secHandY = findPointOnCircle(clockMiddle.x, clockMiddle.y, SEC_HAND_LENGTH, secHandAngle)
    mcdrawing.drawLine(clockMiddle.x, clockMiddle.y, clockMiddle.z + 1, secHandX, secHandY, clockMiddle.z + 1,'STONE')

    time.sleep(1)
    mcdrawing.drawLine(clockMiddle.x, clockMiddle.y, clockMiddle.z, hourHandX, hourHandY, clockMiddle.z, 'AIR')
    mcdrawing.drawLine(clockMiddle.x, clockMiddle.y, clockMiddle.z - 1, minHandX, minHandY, clockMiddle.z - 1,'AIR')
    mcdrawing.drawLine(clockMiddle.x, clockMiddle.y, clockMiddle.z + 1, secHandX, secHandY, clockMiddle.z + 1,'AIR')