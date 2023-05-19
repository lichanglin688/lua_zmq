-- os.execute("start title ZmqMessageRouter")
-- os.execute("start .\\lua.exe ZmqMessageRouter.lua")
os.execute("start \"ZmqMessageRouter\" lua.exe ZmqMessageRouter.lua")
-- os.execute("start \"server1\" /b lua.exe server1.lua")
-- os.execute("start \"server2\" /b lua.exe server2.lua")

os.execute("start \"server1\" lua.exe server1.lua")
os.execute("start \"server2\" lua.exe server2.lua")