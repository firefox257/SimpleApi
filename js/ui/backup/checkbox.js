
import {$} from "/tools.js";

const css = `
.checkbox
{
	padding: 0;
	margin: 0;
	display:inline-block;
	border: 0.7mm solid #888;
	border-radius:1mm;
	position:relative;
	top: 0;
	left: 0;
	width:3mm;
	height: 3mm;
	background-color: #444;
}

`;

const html = `

<span class = "checkbox" tieevents="onclick:onclick" tie="border:style.border">
	<svg
		tie="display:style.display"
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
	   inkscape:version="0.92.5 (2060ec1f9f, 2020-04-08)"
	   sodipodi:docname="checkbox.svg">
	  <metadata
		 id="metadata4572">
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
	  <defs
		 id="defs4570">
		<filter
		   inkscape:collect="always"
		   style="color-interpolation-filters:sRGB"
		   id="filter4690"
		   x="-0.18816798"
		   width="1.376336"
		   y="-0.18863259"
		   height="1.3772652">
		  <feGaussianBlur
			 inkscape:collect="always"
			 stdDeviation="2.1269141"
			 id="feGaussianBlur4692" />
		</filter>
	  </defs>
	  <sodipodi:namedview
		 pagecolor="#ffffff"
		 bordercolor="#666666"
		 borderopacity="1"
		 objecttolerance="10"
		 gridtolerance="10"
		 guidetolerance="10"
		 inkscape:pageopacity="0"
		 inkscape:pageshadow="2"
		 inkscape:window-width="1236"
		 inkscape:window-height="736"
		 id="namedview4568"
		 showgrid="false"
		 inkscape:zoom="3.0807268"
		 inkscape:cx="53.175221"
		 inkscape:cy="49.318257"
		 inkscape:window-x="0"
		 inkscape:window-y="19"
		 inkscape:window-maximized="0"
		 inkscape:current-layer="layer1" />
	  <g
		 inkscape:label="Layer 1"
		 inkscape:groupmode="layer"
		 id="layer1">
		<path
			tie="color:style.fill"
		   style="fill:#00ff00;stroke:none;stroke-width:0.264583px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1;fill-opacity:1"
		   d="M 2.2049736,13.697563 11.826676,21.381562 29.33283,1.6036172 11.492589,28.664656 Z"
		   id="path1402" />
		<path
			tie="color1:style.fill"
		   inkscape:connector-curvature="0"
		   style="fill:#00ff00;fill-opacity:1;stroke:none;stroke-width:0.26458299px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1;filter:url(#filter4690)"
		   d="M 2.2049736,13.697564 11.826676,21.381563 29.33283,1.6036176 11.492589,28.664656 Z"
		   id="path1402-6" />
	  </g>
	</svg>
</span>



`;



function checkboxfunc()
{
	var at = 
	{
		attributes:
		{
			get checked()
			{
				if(at.display=="none") return 0;
				return 1;
			},
			set checked(v)
			{
				if(v==0)
				{
					at.display= "none";
				}
				else
				{
					at.display = "";
				}
			},
			get color()
			{
				return at.color;
			},
			set color(v)
			{
				at.color = v;
				at.color1=v;
			},
			onchange: undefined
		},//end attributes
		onclick(e)
		{
			if(at.attributes.checked == 1) at.attributes.checked = 0;
			else at.attributes.checked = 1;
			if(at.attributes.onchange)at.attributes.onchange(at.attributes.checked);
		},
		color:"#00bbff",
		color1:"#00bbff",
		display: "none", 
		border: "0.7mm solid #888", 
		
	};
	return at;
}
checkboxfunc.css = css;
checkboxfunc.html = html;

$.comp("checkbox", checkboxfunc);
