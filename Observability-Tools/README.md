# Observability Tools 

These folders contain modified versions of the some of the code that I used to deploy a scalable observability stack on Red Hat OpenShift. 
It consisted of tools such as Prometheus, Grafana, Grafana Loki, Grafana Mimir, Promtail and Otel.
Of those, I have included Prometheus, Grafana, Loki and Promtail.

- Prometheus - a simple deployment of this monitoring tool, used to target servers and collect relevant logs.
- Grafana - the data collected by Prometheus was pushed to Grafana for visualization in the form of customized dashboards.
- Promtail - I mainly used this to test and monitor my own personal servers.
- Grafana Loki - this app was deployed in the Simple Scalable Deployment (SSD) mode, to ensure scalablity while also reducing complexity to allow for easy rollout across all the managed servers.
