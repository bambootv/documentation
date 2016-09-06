How to change drive letter in windows
================================================

Use `command prompt` as `admistrator`

Tool: `dispart`

Step 1: run `diskpart`

Step 2: List all volume and driver letter

`list volume`

Step 3: Select volume you want to change (ex: `volume 0`)

`select volume 0`

Step 4: Assign letter `H` to drive with `volume 0`

`assign letter H`

Step 5: Exit

`exit`