using System;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Upload(object sender, EventArgs e)
    {
        try
        {
            if (FileUpload1.HasFile)
            {
                string s = "<br><u>File Information</u> ";
                s += "<br>"+"File Name : "+FileUpload1.FileName;
                s += "<br>" + "File Size : " + FileUpload1.FileBytes.Length;
                string[] arr = FileUpload1.FileName.Split(".".ToCharArray());
                string type = arr[arr.Length - 1];
                if (type.Equals("png"))
                    s += "<br>"+"File Type"+  "PNG";
                else if(type.Equals("gif"))
                    s += "<br>" + "File Type" + "GIF";
                else if(type.Equals("jpg")||type.Equals("jpeg"))
                    s += "<br>" + "File Type" + "JPEG";
                else if(type.Equals("pdf"))
                    s += "<br>" + "File Type" + "PDF";
                Literal1.Text = s;
         
                string filename = Request.PhysicalApplicationPath + "/uploads/" + FileUpload1.FileName;
                FileUpload1.SaveAs(filename);
            }
            else
            {
                Literal1.Text = "Invalid File Selection";
            }
        }
        catch (Exception ex)
        {
        }
    }
}
