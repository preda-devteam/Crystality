#! /bin/bash -e

code --install-extension /opt/Crystality/extensions/crystality.vsix
python3 -c 'import os,json
home_dir=os.path.expanduser("~")
setting=os.path.join(home_dir,".config","Code","User","settings.json")
os.makedirs(os.path.dirname(setting), exist_ok=True)
if not os.path.exists(setting):
	open(setting,"w").close()
with open(setting,"r") as f:
	s=f.read()
if len(s) < 2:
	s="{}"
j=json.loads(s)
j["Crystality.path"]="/opt/Crystality/bin/crystality"
with open(setting,"w") as f:
	json.dump(j,f,indent=2)
	f.close()'