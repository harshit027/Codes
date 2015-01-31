<%@ Application Language="C#" %>

<script runat="server">

    void Application_Start(object sender, EventArgs e) 
    {
        Application["sessions"] = 0;

    }
    
    void Application_End(object sender, EventArgs e) 
    {
        //  Code that runs on application shutdown

    }
        
    void Application_Error(object sender, EventArgs e) 
    { 
        

    }

    void Session_Start(object sender, EventArgs e) 
    {
        Application["sessions"] = (int)Application["sessions"] + 1;

    }

    void Session_End(object sender, EventArgs e) 
    {
        Application["sessions"] = (int)Application["sessions"] - 1;

    }
       
</script>
