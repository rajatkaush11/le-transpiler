import subprocess
from fnmatch import fnmatch
import os
import sys

for file in os.listdir("tests/run_anywhere"):
    if fnmatch(file, "*.test"):
        print(f"    ")
        print("Running test ", file)

        transpile_output = subprocess.run(f"bin/le-transpiler --preprocess -t tests/run_anywhere/{file}", shell=True, capture_output=True)

        if transpile_output.returncode != 0:
            print(f"**** ****TEST FAILED**** ****: {file}")
            print("stdout:\n", transpile_output.stdout.decode("utf-8"), sep='')
            print("stderr:\n", transpile_output.stderr.decode("utf-8"), sep='')
            sys.exit(1)

        compile_output = subprocess.run(f"gcc -o tests/run_anywhere/{file}.out /tmp/temp.c", shell=True, capture_output=True)

        if compile_output.returncode != 0:
            print(f"**** ****TEST FAILED**** ****: {file}")
            print("stdout:\n", compile_output.stdout.decode("utf-8"), sep='')
            print("stderr:\n", compile_output.stderr.decode("utf-8"), sep='')
            sys.exit(1)

        run_output = subprocess.run(f"tests/run_anywhere/{file}.out", shell=True, capture_output=True)

        if run_output.returncode != 0:
            print(f"**** ****TEST FAILED**** ****: {file}")
            print("stdout:\n", run_output.stdout.decode("utf-8"), sep='')
            print("stderr:\n", run_output.stderr.decode("utf-8"), sep='')
            sys.exit(1)
        else:
            output = run_output.stdout
        with open(f"tests/run_anywhere/{file}.output", 'r+b') as out:
            expected_output = out.read()

        if output != expected_output:
            print(f"**** ****TEST FAILED**** ****: {file}")
            print(f"Standard Output:{output}")
            print(f"Expected Output:{expected_output}")
            sys.exit(1)
        else:
            print(f"Test {file} passed")
            print(f"Standard Output:{output}")
            print(f"Expected Output:{expected_output}")