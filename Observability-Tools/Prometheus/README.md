The files here can help you test a simple deployment of Prometheus on, say, a minikube cluster. 

Simply run the following lines of code in your Powershell (or equivalent):


1. Enter this directory

2. Run
>kubectl create -f .

3. Use port-forwarding to expose the service
>kubectl port-forward svc/prometheus-service 9090:9090 -n default

4. Access the app in your web browser at http://localhost:9090

