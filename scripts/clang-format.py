import glob
import os

path = os.path.abspath(os.path.join(__file__, os.pardir))
path = os.path.abspath(os.path.join(path, os.pardir))
path = os.path.join(path, "include")
files = [f for f in glob.glob(path + "/**/*.hpp", recursive=True)]
for f in files:
    command = "clang-format -i {}".format(f)
    print("[clang-format.py]: {}".format(command))
    os.system(command)