
import {$} from "/tools.js";

const css = `
.checkbox
{
	padding: 0;
	margin: 0;
	display:inline-block;
	border: 0.7mm solid #ccc;
	border-radius:2mm;
	position:relative;
	top: 0;
	left: 0;
	width:5mm;
	height: 5mm;
	background-color: #777;
}
.checkboxhide-on-start
{
	position: absolute;
	top: 0;
	left: 0;
	overflow:hidden;
	width: 100%;
	height: 100%;
	transform: translate(0%, 0);
}
.checkboximg-on-start
{
	transform: translate(0%, 0);
}

.checkboxhide-off-start
{
	position: absolute;
	top: 0;
	left: 0;
	overflow:hidden;
	width: 100%;
	height: 100%;
	transform: translate(-100%, 0);
}
.checkboximg-off-start
{
	transform: translate(100%, 0);
}



@keyframes turnoffhide
{
	from {transform: translate(0, 0);}
	to {transform: translate(-100%, 0);}
}

@keyframes turnoff
{
	from {transform: translate(0, 0);}
	to {transform: translate(100%, 0);}
}

@keyframes turnonhide
{
	from {transform: translate(-100%, 0);}
	to {transform: translate(0, 0);}
}

@keyframes turnon
{
	from {transform: translate(100%, 0);}
	to {transform: translate(0, 0);}
}


`;

const html = `

<span class = "checkbox">
<span tieclass="classhide">
	<svg
		tieclass="class"
	   xmlns:dc="http://purl.org/dc/elements/1.1/"
	   xmlns:cc="http://creativecommons.org/ns#"
	   xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
	   xmlns:svg="http://www.w3.org/2000/svg"
	   xmlns="http://www.w3.org/2000/svg"
	   xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd"
	   xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape"
	   width="100%"
	   height="100%"
	   viewBox="0 0 30 30"
	   version="1.1"
	   id="svg8"
	   inkscape:version="1.0.2 (e86c870879, 2021-01-15)"
	   sodipodi:docname="checkbox.svg">
	  <defs
		 id="defs2">
		<filter
		   style="color-interpolation-filters:sRGB;"
		   inkscape:label="Drop Shadow"
		   id="filter1035">
		  <feFlood
			 flood-opacity="0.498039"
			 flood-color="rgb(0,0,0)"
			 result="flood"
			 id="feFlood1025" />
		  <feComposite
			 in="flood"
			 in2="SourceGraphic"
			 operator="in"
			 result="composite1"
			 id="feComposite1027" />
		  <feGaussianBlur
			 in="composite1"
			 stdDeviation="1"
			 result="blur"
			 id="feGaussianBlur1029" />
		  <feOffset
			 dx="1"
			 dy="1"
			 result="offset"
			 id="feOffset1031" />
		  <feComposite
			 in="SourceGraphic"
			 in2="offset"
			 operator="over"
			 result="composite2"
			 id="feComposite1033" />
		</filter>
	  </defs>
	  <sodipodi:namedview
		 id="base"
		 pagecolor="#ffffff"
		 bordercolor="#666666"
		 borderopacity="1.0"
		 inkscape:pageopacity="0.0"
		 inkscape:pageshadow="2"
		 inkscape:zoom="3.959798"
		 inkscape:cx="85.67021"
		 inkscape:cy="66.055813"
		 inkscape:document-units="mm"
		 inkscape:current-layer="layer1"
		 inkscape:document-rotation="0"
		 showgrid="false"
		 inkscape:window-width="1551"
		 inkscape:window-height="1040"
		 inkscape:window-x="104"
		 inkscape:window-y="0"
		 inkscape:window-maximized="0" />
	  <metadata
		 id="metadata5">
		<rdf:RDF>
		  <cc:Work
			 rdf:about="">
			<dc:format>image/svg+xml</dc:format>
			<dc:type
			   rdf:resource="http://purl.org/dc/dcmitype/StillImage" />
			<dc:title></dc:title>
		  </cc:Work>
		</rdf:RDF>
	  </metadata>
	  <g
		 inkscape:label="Layer 1"
		 inkscape:groupmode="layer"
		 id="layer1">
		<path tie="color:style.fill"
		   style="fill:#00ff00;fill-opacity:1;stroke:none;stroke-width:0.264583px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1;filter:url(#filter1035)"
		   d="M 0.53453906,13.296659 10.156241,20.980658 27.662395,1.2027129 9.8221545,28.263752 Z"
		   id="path1402"
		   sodipodi:nodetypes="ccccc" />
	  </g>
	</svg>
</span>
</span>



`;



function checkboxfunc()
{
	var at = 
	{
		attributes:
		{
			get state()
			{
				if(at.class =="checkbox-on" || at.class == "checkbox-on-start") return true;
				return false;
			},
			set state(v)
			{
				if(v)
				{
					if(at.class == "checkbox-off-start")
					{
						if(at.hasafter)
						{ 
							at.class = "checkbox-on";
							at.classhide = "checkboxhide-on";
						}
						else 
						{
							at.class = "checkbox-on-start";
							at.classhide = "checkboxhid-on-start";
						}
					}
				}
				else
				{
					if(at.class == "checkbox-on-start")
					{
						if(at.hasafter)
						{
							at.class = "checkbox-off";
							at.classhide="checkboxhide-off";
						}
						else
						{
							at.class="checkbox-off-start";
							at.classhide = "checkboxhide-off-start";
						}
						
					}
				}
			}//end attributes
		},
		hasafter:false,
		color:"#00bbff",
		classhide:"checkboxhide-off-start",
		class:"checkbox-off-start",
		afterinit()
		{
			at.hasafter =true;
		}
	};
	return at;
}
checkboxfunc.css = css;
checkboxfunc.html = html;

$.comp("checkbox", checkboxfunc);
