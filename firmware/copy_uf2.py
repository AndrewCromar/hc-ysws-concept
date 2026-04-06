import shutil
import os

Import("env")

def copy_uf2(*args, **kwargs):
    src = os.path.join(env.subst("$BUILD_DIR"), "firmware.uf2")
    dst = os.path.join(env.subst("$PROJECT_DIR"), "..", "production", "firmware.uf2")
    if os.path.exists(src):
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy2(src, dst)
        print(f"Copied firmware.uf2 to {dst}")

env.AddPostAction("buildprog", copy_uf2)
