import testyx

sys = testyx.system()


sys.parseSensor("./data/Sensors.csv")

sys.parseAttribute("./data/AttributeType.csv")

sys.parseData("./data/data_10sensors_1year.csv")

sys.menu()