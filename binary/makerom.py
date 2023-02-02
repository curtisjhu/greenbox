rom = bytearray([0xea], 32768)

rom[0] = 0x60

with open("rom.bin", "wb") as output_file:
	output_file.write(rom)
