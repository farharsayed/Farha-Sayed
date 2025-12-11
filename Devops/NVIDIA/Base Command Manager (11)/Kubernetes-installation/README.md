# Kubernetes Installation on NVIDIA Base Command Manager

Below are the steps I used to install and set up a Kubernetes cluster on NVIDIA Base Command Manager running in an air-gapped system. This is only my personal documentation of the project.
I used the following documentation for this task:
[Kubernetes installation on Air-Gapped BCM](https://kb.brightcomputing.com/knowledge-base/)

Step 1: Prepare the software images
Install the required RPM packages and dependencies on the software images which will be stored on the head node/s.
The list of packages is available in the documentation.

Step 2: Setup a local container registry on the headnode
I chose a Docker registry for my use-case. Run the following command on the primary active headnode to do the setup.
>cm-container-registry-setup

Step 3: Start up the Docker service and verify
>systemctl start docker.service
>module load docker
>systemctl start docker
>docker ps

Step 4: Prepare the container images
Save these in the local registry from Step 3.

Step 5: Create the config file for the Kubernetes installation.
Run the following command and select the configuration but on the last slide select "Save and Exit".
NOTE: You do not want to install as yet.
Please ensure to select the default version of Kubernetes given in the setup.
>cm-kubernetes-setup --skip-packages

Step 6: Edit the conf file cm-kubernetes-setup.conf which will be saved locally on your headnode at /root/cm-kubernetes-setup.conf
Add your custom information in the fields mentioned in the txt file.

Step 7: Deploy K8s
>cm-kubernetes-setup -v -c /root/cm-kubernetes-setup.conf
The flag '-c' points it to the updated conf file and '-v' provides verbose logs during the installation.
