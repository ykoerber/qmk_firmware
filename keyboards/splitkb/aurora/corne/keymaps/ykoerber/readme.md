# make
your corne mx keyboard (wooden case)


## with docker
```bash
export MAKEFLAGS="CONVERT_TO=elite_pi"  
util/docker_build.sh splitkb/aurora/corne/rev1:ykoerber
```

## does not work anymore 
```bash
make splitkb/aurora/corne/rev1:ykoerber -e CONVERT_TO=promicro_rp2040
```


export LDFLAGS="-L/opt/homebrew/opt/arm-none-eabi-gcc@8/lib"
echo 'export PATH="/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:$PATH"' >> ~/.zshrc

brew link arm-none-eabi-gcc:8 --force
