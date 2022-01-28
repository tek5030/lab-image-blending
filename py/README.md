# Getting started with Python

## Installing a newer version of Python [[1][1]]

```bash
sudo apt update
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt install python3.9-dev python3.9-venv python3-pip
```

## Setup a new virtual environment with the installed Python version

In a terminal, run the following command:

```bash
python3.9 -m venv venv
source venv/bin/activate
pip install --upgrade pip

# type 'deactivate' or close the terminal to exit the virtual environment
```

## Developing on a remote host

### Install Visual Studio Code

```bash
sudo snap install --classic code
```

#### Install extensions

After launching VS Code, press `Ctrl+Shift-X`

Install the following, selecting those marked with a star and "Microsoft"

- Remote Development
- Python

### Set up a connection to develop on a remote host

Trykk helt nederst til venstre i Visual Studio Code vinduet for å sette opp en ny remote tilkobling. TBD.

## Troubleshooting

- **Q:** [Installing OpenCV fails because it cannot find "skbuild"](https://stackoverflow.com/a/63457606/14325545)
- **A:** Upgrade pip: `pip install --upgrade pip`

## References

The following links were used when writing this tutorial:

1. [How to Install Python 3.9 on Ubuntu][1]
2. [Using Python environments in VS Code][2]
3. [Installing packages using pip and virtual environments][3]

[1]: https://tech.serhatteker.com/post/2020-09/how-to-install-python39-on-ubuntu/
[2]: https://code.visualstudio.com/docs/python/environments
[3]: https://packaging.python.org/en/latest/guides/installing-using-pip-and-virtual-environments/