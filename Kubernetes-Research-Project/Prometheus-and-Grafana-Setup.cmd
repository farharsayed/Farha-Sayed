REM Script for installing and setting up Prometheus and Grafana (to be repeated on each cluster):


REM 1. Open Azure Cloud Shell and connect to the cluster

REM 2. Download Helm onto the cluster

REM 3. Download prometheus-community repository Helm Chart 
  helm repo add prometheus-community https://prometheus-community.github.io/helm-charts

REM 4. Install prometheus stack into a new namespace called monitoring
  helm install prometheus prometheus-community/kube-prometheus-stack --namespace monitoring --create-namespace

REM 5. Check the newly installed features
  kubectl get all -n monitoring
REM OR, using 
  kubectl --namespace monitoring get pods -l "release=prometheus"

REM 6. Change the Alert Manager, Prometheus and Grafana service types to LoadBalancer by using the following commands to view and edit them respectively:

  kubectl describe svc prometheus-kube-prometheus-alertmanager -n monitoring
  kubectl describe svc prometheus-kube-prometheus-prometheus -n monitoring
  kubectl describe svc prometheus-grafana -n monitoring


  kubectl edit svc prometheus-kube-prometheus-alertmanager -n monitoring
  kubectl edit svc prometheus-kube-prometheus-prometheus -n monitoring
  kubectl edit svc prometheus-grafana -n monitoring

REM 7. Confirm changes by viewing them with:
  kubectl get svc -n monitoring



