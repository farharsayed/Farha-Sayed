# Grafana

The files here can help you test a simple deployment of the [Grafana](https://grafana.com/) application.
You can try it out yourself on a [minikube](https://minikube.sigs.k8s.io/docs/) cluster. 
Note: You will need to have the [kubectl utility](https://kubernetes.io/docs/tasks/tools/#kubectl) installed on your device. 

Simply run the following lines of code in Powershell (or equivalent):


1. Enter this directory

2. Run
>kubectl create -f .

3. Use port-forwarding to expose the service
>kubectl port-forward svc/grafana-service 3000:80 -n default

4. Access the app in your web browser at http://localhost:3000

