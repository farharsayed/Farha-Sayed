REM Script for the 4 cluster setups are outlined below.


REM 1. Create each of the 4 clusters using the specifications mentioned in the report.


REM 2. Deploying TeaStore in every cluster

REM We create and save the TeaStore YAML file. This command can also be used to edit the document once it is created.
REM NOTE: If we edit the teastore-clusterip.yaml file, we must delete our previous deployment and redeploy the newly edited version.
nano teastore-clusterip.yaml

REM We deploy the TeaStore file linked in the main repo.
kubectl create -f teastore-clusterip.yaml

REM If we have to delete our deployment we do so using:
REM kubectl delete -f teastore-clusterip.yaml


REM 3. Deploying Horizontal Pod Autoscaling object in every cluster

REM We create and save the HPA YAML file linked in the main repo. This command can also be used to edit the document once it is created.
REM NOTE: If we edit the hpa.yaml file, we must delete our previous deployment and redeploy the newly edited version.
nano hpa.yaml

REM We deploy the HPA object.  
kubectl create -f hpa.yaml

REM Similar to the previous step, if we have to delete our deployment we do so by:
REM kubectl delete -f hpa.yaml


REM 4. Set up Prometheus by following the instructions from Prometheus-and-Grafana-Setup.cmd




