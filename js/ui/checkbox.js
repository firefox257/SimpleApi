
import {$} from "/tie.js";

const css = `
.checkbox-unchecked
{
	padding: 0;
	margin: 0.3mm;
	display:inline-block;
	border: 0.4mm solid #888;
	border-radius:1mm;
	position:relative;
	top: 0;
	left: 0;
	width:3mm;
	height: 3mm;
	background-color: #444 !important;
}
.checkbox-unchecked  svg
{
	display: none;
}

.checkbox-checked
{
	padding: 0;
	margin: 0;
	display:inline-block;
	border-radius:1mm;
	border: 0.7mm solid;
	position:relative;
	top: 0;
	left: 0;
	width:3mm;
	height: 3mm;
	background-color: #00ff88;
	box-shadow: 0 0 3mm;
}

`;

const html = `

<span tieclass = "class" tieevents="onclick:onclick" tie="color:style.backgroundColor, color1:style.color">
	<svg
	style = "position:absolute; top: 0; left; 0;"
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
	   sodipodi:docname="checkboxv2.svg">
	 
	  <g
		 inkscape:label="Layer 1"
		 inkscape:groupmode="layer"
		 id="layer1"
		 transform="translate(0,-267)">
		<path
		   style="fill:#000000;fill-opacity:1;stroke:none;stroke-width:0.20486294;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1"
		   d="m 14.861633,293.089 -0.489279,0.6999 -6.5931355,-4.3744 -6.5931265,-4.37437 1.5732544,-2.37124 1.5732529,-2.37122 4.223042,2.80188 4.2230507,2.8019 5.453948,-8.22026 5.453945,-8.22028 2.371232,1.57326 2.371231,1.57325 -4.894628,7.37726 c -2.692043,4.05748 -5.634248,8.50862 -6.539068,9.89084 -0.904724,1.3823 -1.864382,2.8287 -2.133527,3.2136 z"
		   id="path934"
		   inkscape:connector-curvature="0" />
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
				return at.class =="checkbox-checked";
			},
			set checked(v)
			{
				if(v==0)
				{
					at.class = "checkbox-unchecked";
				}
				else
				{
					at.class = "checkbox-checked";
				}
			},
			get color()
			{
				return at.color;
			},
			set color(v)
			{
				at.color = v;
				at.color1 = v;
			},
			onchange: undefined
		},//end attributes
		onclick(e)
		{
			if(at.attributes.checked == 1) at.attributes.checked = 0;
			else at.attributes.checked = 1;
			if(at.attributes.onchange)at.attributes.onchange(at.attributes.checked);
		},
		class: "checkbox-unchecked",
		color:"#00bbff",
		color1: "#00bbff"
	};
	return at;
}
checkboxfunc.css = css;
checkboxfunc.html = html;

$.comp("checkbox", checkboxfunc);
