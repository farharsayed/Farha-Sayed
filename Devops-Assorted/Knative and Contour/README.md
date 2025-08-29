# Knative and Contour

##Domain Mapping:
Knative Services (ksvc's) are given a default domain name when they are created, but we can customize them with the steps below.

- Step 1: Create a Kubernetes TLS Secret 
>kubectl create tls <name> --cert=path/to/cert/file --key=path/to/key/file 

- Step 2: Create a ClusterDomainClaim
Use the YAML file to create a ClusterDomainClaim Knative Resource, providing the domain-name "farhasayed.example.com" and the namespace.

- Step 3: Create the DomainMapping
Use the YAML to create a DomainMapping Knative resource, providing the ksvc service-name, domain-name, namespace and the name of the Kubernetes secret created in step 1.

You should now be able to access the resource via the custom domain name.


