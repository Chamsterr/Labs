﻿using System.Data.Services.Common;
using System.Data.Services;
using System.Data.Services.Providers;
using System.Linq;
using System;
using System.ServiceModel.Web;
using System.ServiceModel.Activation;

namespace PWS_Lab6
{

    [AspNetCompatibilityRequirements(RequirementsMode = AspNetCompatibilityRequirementsMode.Allowed)]
    public class Service1 : EntityFrameworkDataService<StudentsEntities1>
    {
        public static void InitializeService(DataServiceConfiguration config)
        {
            config.SetEntitySetAccessRule("*", EntitySetRights.All);
            config.SetServiceOperationAccessRule("*", ServiceOperationRights.All);
            config.DataServiceBehavior.MaxProtocolVersion = DataServiceProtocolVersion.V3;
            config.UseVerboseErrors = true;
        }
    }
}
