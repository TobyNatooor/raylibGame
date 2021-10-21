import matplotlib.pyplot as plt

leftData1 = [ 
    [0, -0.351798, -0.009760, -0.026651],
    [1, -0.351798, -0.009760, -0.026651],
    [2, -0.351798, -0.009760, -0.026651],
    [3, -0.351798, -0.009760, -0.026651],
    [4, -0.351798, -0.009760, -0.026651],
    [5, -0.351952, -0.009760, -0.024540],
    [6, -0.352158, -0.009760, -0.021371],
    [7, -0.352439, -0.009760, -0.016087],
    [8, -0.352641, -0.009760, -0.010799],
    [9, -0.352745, -0.009760, -0.006566],
    [10, -0.352806, -0.009760, -0.000216],
    [11, -0.352520, -0.011877, 0.012480],
    [12, -0.351686, -0.011877, 0.027270],
    [13, -0.349664, -0.012935, 0.046208],
    [14, -0.347044, -0.012935, 0.062932],
    [15, -0.343385, -0.012935, 0.080542],
    [16, -0.339125, -0.012935, 0.096925],
    [17, -0.334084, -0.012935, 0.113085],
    [18, -0.327884, -0.012935, 0.129969],
    [19, -0.322633, -0.010818, 0.142683],
    [20, -0.316877, -0.008702, 0.155180],
    [21, -0.312594, -0.007643, 0.163689],
    [22, -0.309135, -0.004467, 0.170243],
    [23, -0.306039, -0.002350, 0.175790],
    [24, -0.302286, 0.000827, 0.182181],
    [25, -0.298394, 0.000827, 0.188488],
    [26, -0.294943, 0.002945, 0.193823],
    [27, -0.289595, 0.004003, 0.201708],
    [28, -0.282782, 0.004003, 0.211154],
    [29, -0.274988, 0.005062, 0.221186],
    [30, -0.265446, 0.006121, 0.232526],
    [31, -0.253952, 0.008238, 0.244965],
    [32, -0.241134, 0.008238, 0.257593],
    [33, -0.230106, 0.008238, 0.267490],
    [34, -0.219501, 0.008238, 0.276258],
    [35, -0.201673, 0.008238, 0.289530],
    [36, -0.196429, 0.008238, 0.293113],
    [37, -0.184864, 0.007179, 0.300568],
    [38, -0.166508, 0.007179, 0.311113],
    [39, -0.158048, 0.007179, 0.315495],
    [40, -0.132991, 0.006121, 0.326869],
    [41, -0.115155, 0.006121, 0.333571],
    [42, -0.096983, 0.006121, 0.339300],
    [43, -0.078532, 0.005062, 0.344056],
    [44, -0.055670, 0.005062, 0.348486],
    [45, -0.033619, 0.005062, 0.351300],
    [46, -0.013552, 0.005062, 0.352645],
    [47, 0.007619, 0.005062, 0.352823],
    [48, 0.027706, 0.005062, 0.351816],
    [49, 0.046654, 0.005062, 0.349807],
    [50, 0.064426, 0.005062, 0.346974],
    [51, 0.083060, 0.005062, 0.342991],
    [52, 0.099417, 0.006121, 0.338595],
    [53, 0.116534, 0.008238, 0.333046],
    [54, 0.131377, 0.010355, 0.327414],
    [55, 0.138197, 0.012471, 0.324521],
    [56, 0.161147, 0.014588, 0.313666],
    [57, 0.177819, 0.015645, 0.304472],
    [58, 0.193967, 0.016703, 0.294390],
    [59, 0.210423, 0.016703, 0.282862],
    [60, 0.226937, 0.018818, 0.269653],
    [61, 0.244187, 0.019875, 0.254058],
    [62, 0.260366, 0.020932, 0.237359],
    [63, 0.275350, 0.023046, 0.219588],
    [64, 0.287964, 0.024102, 0.202641],
    [65, 0.300573, 0.026215, 0.183130],
    [66, 0.312412, 0.027270, 0.161934],
    [67, 0.321911, 0.028326, 0.141910],
    [68, 0.325943, 0.029381, 0.132158],
    [69, 0.337438, 0.032545, 0.098204],
    [70, 0.340657, 0.033599, 0.085971],
    [71, 0.345381, 0.035707, 0.063280],
    [72, 0.349538, 0.040970, 0.026689],
    [73, 0.350300, 0.043072, 0.001474],
    [74, 0.349304, 0.045173, -0.022664],
    [75, 0.346909, 0.047273, -0.044575],
    [76, 0.341881, 0.049370, -0.072438],
    [77, 0.334907, 0.051466, -0.098772],
    [78, 0.324142, 0.052514, -0.129389],
    [79, 0.308656, 0.053560, -0.162574],
    [80, 0.291076, 0.053560, -0.192285],
    [81, 0.258952, 0.054607, -0.233515],
    [82, 0.246594, 0.055652, -0.246296],
    [83, 0.221043, 0.055652, -0.269463],
    [84, 0.196601, 0.057743, -0.287369],
    [85, 0.172619, 0.058787, -0.302183],
    [86, 0.151218, 0.060874, -0.313042],
    [87, 0.134030, 0.061917, -0.320577],
    [88, 0.117386, 0.064000, -0.326637],
    [89, 0.103451, 0.066082, -0.330906],
    [90, 0.091314, 0.069199, -0.333827],
    [91, 0.078133, 0.071274, -0.336723],
    [92, 0.066896, 0.073347, -0.338692],
    [93, 0.056671, 0.074383, -0.340328],
    [94, 0.050503, 0.075417, -0.341071],
    [95, 0.030949, 0.077485, -0.342937],
    [96, 0.007217, 0.080580, -0.343544],
    [97, -0.018545, 0.080580, -0.343119],
    [98, -0.046247, 0.080580, -0.340493],
    [99, -0.077667, 0.080580, -0.334727],
    [100, -0.104569, 0.079549, -0.327574],
    [101, -0.127951, 0.078517, -0.319423],
    [102, -0.146875, 0.078517, -0.311176],
    [103, -0.167077, 0.078517, -0.300812],
    [104, -0.184815, 0.078517, -0.290252],
    [105, -0.201748, 0.079549, -0.278455],
    [106, -0.215680, 0.079549, -0.267808],
    [107, -0.227509, 0.079549, -0.257835],
    [108, -0.235892, 0.079549, -0.250188],
    [109, -0.242561, 0.079549, -0.243729],
    [110, -0.252755, 0.078517, -0.233490],
    [111, -0.263181, 0.077485, -0.222035],
    [112, -0.272454, 0.076451, -0.210930],
    [113, -0.282448, 0.075417, -0.197745],
    [114, -0.291247, 0.074383, -0.184959],
    [115, -0.306889, 0.073347, -0.158135],
    [116, -0.317671, 0.072311, -0.135734],
    [117, -0.327486, 0.071274, -0.110637],
    [118, -0.335317, 0.070237, -0.084835],
    [119, -0.341081, 0.070237, -0.057426],
    [120, -0.344609, 0.070237, -0.029640],
    [121, -0.345878, 0.070237, -0.001660],
    [122, -0.344714, 0.070237, 0.028399],
    [123, -0.340766, 0.070237, 0.059267],
    [124, -0.332986, 0.067121, 0.095824],
    [125, -0.321684, 0.066082, 0.129306],
    [126, -0.306045, 0.065041, 0.163320],
    [127, -0.286387, 0.062959, 0.196433],
    [128, -0.263545, 0.062959, 0.226158],
    [129, -0.225999, 0.062959, 0.263682],
    [130, -0.201385, 0.062959, 0.282927],
    [131, -0.176040, 0.062959, 0.299355],
    [132, -0.150303, 0.062959, 0.313070],
    [133, -0.123506, 0.062959, 0.324577],
    [134, -0.095838, 0.062959, 0.333794],
    [135, -0.070557, 0.062959, 0.340037],
    [136, -0.048004, 0.061917, 0.344136],
    [137, -0.027281, 0.061917, 0.346395],
    [138, -0.009593, 0.060874, 0.347520],
    [139, 0.017525, 0.059831, 0.347391],
    [140, 0.024816, 0.059831, 0.346947],
    [141, 0.050794, 0.057743, 0.344461],
    [142, 0.067296, 0.056698, 0.341795],
    [143, 0.083659, 0.055652, 0.338336],
    [144, 0.098887, 0.053560, 0.334545],
    [145, 0.114929, 0.051466, 0.329712],
    [146, 0.134610, 0.049370, 0.322506],
    [147, 0.156717, 0.046223, 0.312843],
    [148, 0.179022, 0.043072, 0.301104],
    [149, 0.218296, 0.037813, 0.274744],
    [150, 0.242258, 0.035707, 0.254172],
    [151, 0.269158, 0.032545, 0.225970],
    [152, 0.286101, 0.030436, 0.204419],
    [153, 0.302395, 0.028326, 0.179785],
    [154, 0.309677, 0.028326, 0.166929],
    [155, 0.327046, 0.028326, 0.129638],
    [156, 0.334884, 0.028326, 0.107787],
    [157, 0.341263, 0.028326, 0.085466],
    [158, 0.345882, 0.029381, 0.063795],
    [159, 0.348774, 0.031491, 0.043964],
    [160, 0.350616, 0.032545, 0.024017],
    [161, 0.351315, 0.033599, 0.004002],
    [162, 0.351001, 0.034653, -0.012855],
    [163, 0.349690, 0.035707, -0.031772],
    [164, 0.347763, 0.035707, -0.048514],
    [165, 0.344731, 0.036760, -0.066159],
    [166, 0.341159, 0.036760, -0.082623],
    [167, 0.333024, 0.036760, -0.110955],
    [168, 0.325772, 0.036760, -0.130725],
    [169, 0.317347, 0.036760, -0.150025],
    [170, 0.307272, 0.036760, -0.169707],
    [171, 0.294840, 0.036760, -0.190488],
    [172, 0.282262, 0.036760, -0.208672],
    [173, 0.267204, 0.036760, -0.227636],
    [174, 0.247163, 0.036760, -0.249253],
    [175, 0.230257, 0.035707, -0.265093],
    [176, 0.208901, 0.035707, -0.282229],
    [177, 0.187166, 0.035707, -0.297088],
    [178, 0.155943, 0.035707, -0.314602],
    [179, 0.132907, 0.035707, -0.325005],
    [180, 0.109149, 0.036760, -0.333621],
    [181, 0.087900, 0.037813, -0.339722],
    [182, 0.063233, 0.037813, -0.345165],
    [183, 0.040331, 0.037813, -0.348584],
    [184, 0.016202, 0.037813, -0.350536],
    [185, -0.008004, 0.037813, -0.350818],
    [186, -0.033220, 0.037813, -0.349334],
    [187, -0.058265, 0.037813, -0.346039],
    [188, -0.080960, 0.037813, -0.341443],
    [189, -0.104308, 0.037813, -0.335049],
    [190, -0.128140, 0.037813, -0.326677],
    [191, -0.151309, 0.037813, -0.316612],
    [192, -0.170942, 0.037813, -0.306458],
    [193, -0.189011, 0.037813, -0.295656],
    [194, -0.208099, 0.037813, -0.282547],
    [195, -0.222159, 0.038866, -0.271482],
    [196, -0.237264, 0.038866, -0.258385],
    [197, -0.250864, 0.038866, -0.245202],
    [198, -0.264337, 0.039918, -0.230435],
    [199, -0.273779, 0.039918, -0.219133],
    [200, -0.283359, 0.039918, -0.206595],
    [201, -0.292366, 0.039918, -0.193639],
    [202, -0.301321, 0.039918, -0.179388],
    [203, -0.309966, 0.040970, -0.163737],
    [204, -0.318239, 0.042021, -0.146716],
    [205, -0.325575, 0.043072, -0.129279],
    [206, -0.331061, 0.043072, -0.114502],
    [207, -0.335577, 0.043072, -0.100501],
    [208, -0.339758, 0.043072, -0.085303],
    [209, -0.343332, 0.044123, -0.068877],
    [210, -0.346083, 0.044123, -0.053362],
    [211, -0.348458, 0.044123, -0.034605],
    [212, -0.349604, 0.044123, -0.019944],
    [213, -0.350171, 0.044123, -0.001045],
    [214, -0.349818, 0.044123, 0.015758],
    [215, -0.348659, 0.044123, 0.032524],
    [216, -0.346547, 0.044123, 0.050256],
    [217, -0.342910, 0.044123, 0.070946],
    [218, -0.335449, 0.044123, 0.100473],
    [219, -0.329660, 0.043072, 0.118476],
    [220, -0.323192, 0.043072, 0.135127],
    [221, -0.315083, 0.042021, 0.153376],
    [222, -0.305834, 0.042021, 0.171077],
    [223, -0.294561, 0.040970, 0.190060],
    [224, -0.280757, 0.040970, 0.209916],
    [225, -0.267166, 0.038866, 0.227331],
    [226, -0.250939, 0.037813, 0.245290],
    [227, -0.234998, 0.037813, 0.260602],
    [228, -0.216541, 0.036760, 0.276272],
    [229, -0.198718, 0.036760, 0.289357],
    [230, -0.177442, 0.035707, 0.302996],
    [231, -0.154286, 0.034653, 0.315535],
    [232, -0.127377, 0.031491, 0.327645],
    [233, -0.084191, 0.030436, 0.341398],
    [234, -0.070816, 0.030436, 0.344421],
    [235, -0.029083, 0.029381, 0.350512],
    [236, -0.000627, 0.029381, 0.351716],
    [237, 0.030987, 0.029381, 0.350348],
    [238, 0.061296, 0.030436, 0.346243],
    [239, 0.094202, 0.030436, 0.338773],
    [240, 0.130169, 0.030436, 0.326645],
    [241, 0.168199, 0.033599, 0.308460],
    [242, 0.202195, 0.033599, 0.287325],
    [243, 0.238812, 0.036760, 0.257265],
    [244, 0.272989, 0.039918, 0.220115],
    [245, 0.303873, 0.039918, 0.175029],
    [246, 0.327404, 0.043072, 0.124575],
    [247, 0.341403, 0.045173, 0.077270],
    [248, 0.348738, 0.046223, 0.028513],
    [249, 0.336156, 0.050419, -0.094999],
    [250, 0.318617, 0.053560, -0.142064],
    [251, 0.297124, 0.057743, -0.181523],
    [252, 0.273483, 0.060874, -0.214637],
    [253, 0.249215, 0.062959, -0.241859],
    [254, 0.226877, 0.066082, -0.262159],
    [255, 0.204562, 0.069199, -0.279166],
    [256, 0.182846, 0.071274, -0.293351],
    [257, 0.160150, 0.073347, -0.305842],
    [258, 0.138593, 0.074383, -0.315953],
    [259, 0.114379, 0.076451, -0.325023],
    [260, 0.091575, 0.078517, -0.331688],
    [261, 0.070462, 0.079549, -0.336563],
    [262, 0.047024, 0.081611, -0.340141],
    [263, 0.010079, 0.082641, -0.342982],
    [264, -0.015649, 0.082641, -0.342773],
    [265, -0.041289, 0.082641, -0.340636],
    [266, -0.067706, 0.082641, -0.336384],
    [267, -0.093712, 0.082641, -0.330085],
    [268, -0.121076, 0.082641, -0.321059],
    [269, -0.145725, 0.082641, -0.310648],
    [270, -0.170382, 0.082641, -0.297839],
    [271, -0.193072, 0.082641, -0.283657],
    [272, -0.216033, 0.083670, -0.266264],
    [273, -0.239826, 0.083670, -0.245051],
    [274, -0.262679, 0.084698, -0.219985],
    [275, -0.280379, 0.086752, -0.196034],
    [276, -0.295611, 0.087778, -0.171688],
    [277, -0.306958, 0.088803, -0.149861],
    [278, -0.316823, 0.090851, -0.126240],
    [279, -0.325130, 0.091874, -0.102064],
    [280, -0.331088, 0.093917, -0.078282],
    [281, -0.335250, 0.094937, -0.056229],
    [282, -0.337512, 0.095957, -0.038020],
    [283, -0.338783, 0.096975, -0.019731],
    [284, -0.339035, 0.097993, -0.004467],
    [285, -0.339032, 0.097993, 0.004688],
    [286, -0.338487, 0.099009, 0.013827],
    [287, -0.338297, 0.099009, 0.017887],
    [288, -0.338058, 0.099009, 0.021946], 
]
bottomtData1 = [
    [0, -0.021838, 0.352253, -0.002887],
    [1, -0.028142, 0.351800, -0.003548],
    [2, -0.036537, 0.351018, -0.004384],
    [3, -0.044922, 0.350033, -0.005117],
    [4, -0.055352, 0.348520, -0.006137],
    [5, -0.065739, 0.346692, -0.007090],
    [6, -0.070902, 0.345662, -0.007646],
    [7, -0.091411, 0.340763, -0.009581],
    [8, -0.106629, 0.336284, -0.010530],
    [9, -0.120656, 0.331488, -0.011184],
    [10, -0.134445, 0.326108, -0.012056],
    [11, -0.146087, 0.321039, -0.012658],
    [12, -0.157504, 0.315553, -0.013647],
    [13, -0.166906, 0.310669, -0.013957],
    [14, -0.177030, 0.304974, -0.014804],
    [15, -0.186961, 0.298946, -0.015634],
    [16, -0.196688, 0.292593, -0.016448],
    [17, -0.207055, 0.285300, -0.017315],
    [18, -0.217154, 0.277637, -0.018159],
    [19, -0.226164, 0.270296, -0.018912],
    [20, -0.234928, 0.262660, -0.019645],
    [21, -0.244197, 0.254005, -0.020420],
    [22, -0.254672, 0.243492, -0.020527],
    [23, -0.266206, 0.230952, -0.019047],
    [24, -0.277171, 0.217881, -0.016491],
    [25, -0.286108, 0.206030, -0.016162],
    [26, -0.294587, 0.193817, -0.014869],
    [27, -0.301408, 0.183075, -0.014306],
    [28, -0.307277, 0.173019, -0.014585],
    [29, -0.315731, 0.157112, -0.014037],
    [30, -0.320377, 0.147562, -0.012318],
    [31, -0.322553, 0.142736, -0.012401],
    [32, -0.324692, 0.137878, -0.011508],
    [33, -0.326322, 0.133970, -0.011566],
    [34, -0.331720, 0.120141, -0.009765],
    [35, -0.334534, 0.112143, -0.008844],
    [36, -0.337464, 0.103067, -0.007908],
    [37, -0.339840, 0.094937, -0.007964],
    [38, -0.342278, 0.085726, -0.008021],
    [39, -0.344467, 0.076451, -0.008072],
    [40, -0.346605, 0.066082, -0.008122],
    [41, -0.348304, 0.056698, -0.006071],
    [42, -0.349581, 0.048322, -0.005044],
    [43, -0.350999, 0.036760, -0.004011],
    [44, -0.352297, 0.020932, -0.004026],
    [45, -0.352698, 0.012471, -0.004031],
    [46, -0.352885, -0.005526, -0.002974],
    [47, -0.352226, -0.022452, 0.000201],
    [48, -0.348612, -0.055065, 0.002291],
    [49, -0.344900, -0.074836, 0.003301],
    [50, -0.343005, -0.083092, 0.003283],
    [51, -0.334824, -0.111579, 0.003205],
    [52, -0.329085, -0.127516, 0.003150],
    [53, -0.322133, -0.144127, 0.005016],
    [54, -0.315782, -0.157527, 0.005865],
    [55, -0.308850, -0.170650, 0.007590],
    [56, -0.301914, -0.182566, 0.009232],
    [57, -0.292718, -0.196848, 0.011589],
    [58, -0.284754, -0.208121, 0.012985],
    [59, -0.275734, -0.219906, 0.013403],
    [60, -0.267650, -0.229699, 0.013010],
    [61, -0.257058, -0.241521, 0.012495],
    [62, -0.247420, -0.251372, 0.012771],
    [63, -0.235012, -0.262970, 0.013545],
    [64, -0.222105, -0.273962, 0.013469],
    [65, -0.206983, -0.285573, 0.013176],
    [66, -0.199214, -0.291068, 0.012681],
    [67, -0.182342, -0.301967, 0.011607],
    [68, -0.154457, -0.317167, 0.010763],
    [69, -0.134202, -0.326285, 0.009756],
    [70, -0.111446, -0.334786, 0.008102],
    [71, -0.090203, -0.341157, 0.006557],
    [72, -0.068602, -0.346174, 0.004987],
    [73, -0.045681, -0.349957, 0.003321],
    [74, -0.023605, -0.352146, 0.001859],
    [75, -0.006141, -0.352887, 0.000483],
    [76, -0.006141, -0.352887, 0.000483],
    [77, -0.006143, -0.352887, 0.000447],
    [78, -0.006143, -0.352887, 0.000447],
    [79, -0.006142, -0.352887, 0.000465],
    [80, -0.006141, -0.352887, 0.000483],
    [81, -0.006141, -0.352887, 0.000483],
    [82, -0.006146, -0.352887, 0.000410],
]

leftData2 = [
    [0, 1.544760, 10.277606, 15.425560],
    [1, 1.544760, 10.277606, 15.425560],
    [2, 1.544760, 10.277606, 15.425560],
    [3, 1.544760, 10.277606, 15.425560],
    [4, 1.544760, 10.277606, 15.425560],
    [5, 1.546053, 10.277606, 15.435925],
    [6, 1.548730, 10.277606, 15.456638],
    [7, 1.554691, 10.298489, 15.487438],
    [8, 1.560118, 10.308926, 15.518290],
    [9, 1.567515, 10.319361, 15.559379],
    [10, 1.582885, 10.329792, 15.641411],
    [11, 1.600244, 10.340222, 15.723021],
    [12, 1.632024, 10.350647, 15.854771],
    [13, 1.674042, 10.381905, 15.994486],
    [14, 1.728965, 10.413133, 16.151737],
    [15, 1.804696, 10.454717, 16.334209],
    [16, 1.891026, 10.496234, 16.511581],
    [17, 1.979801, 10.516967, 16.675707],
    [18, 2.088389, 10.537681, 16.852097],
    [19, 2.219529, 10.558376, 17.038147],
    [20, 2.389382, 10.579051, 17.246380],
    [21, 2.605576, 10.610023, 17.468086],
    [22, 2.848653, 10.640947, 17.675396],
    [23, 3.085145, 10.682097, 17.839880],
    [24, 3.305379, 10.702634, 17.971769],
    [25, 3.489485, 10.733396, 18.062241],
    [26, 3.773254, 10.764095, 18.179323],
    [27, 3.967515, 10.784528, 18.242737],
    [28, 4.164993, 10.804933, 18.294191],
    [29, 4.324496, 10.815125, 18.328079],
    [30, 4.464833, 10.815125, 18.353508],
    [31, 4.575770, 10.815125, 18.369339],
    [32, 4.727769, 10.815125, 18.385012],
    [33, 4.849669, 10.804933, 18.395044],
    [34, 4.982146, 10.794735, 18.400724],
    [35, 5.125037, 10.784528, 18.400843],
    [36, 5.277896, 10.784528, 18.391775],
    [37, 5.430781, 10.764095, 18.380449],
    [38, 5.602951, 10.753869, 18.356335],
    [39, 5.783744, 10.743635, 18.321085],
    [40, 5.981478, 10.743635, 18.268112],
    [41, 6.185285, 10.743635, 18.199837],
    [42, 6.403990, 10.733396, 18.112522],
    [43, 6.740130, 10.733396, 17.937843],
    [44, 6.982999, 10.712894, 17.785021],
    [45, 7.218867, 10.702634, 17.603802],
    [46, 7.416492, 10.692369, 17.424467],
    [47, 7.626198, 10.682097, 17.198790],
    [48, 7.803082, 10.671818, 16.971863],
    [49, 7.949928, 10.661534, 16.748468],
    [50, 8.074412, 10.651242, 16.523390],
    [51, 8.185568, 10.640947, 16.279921],
    [52, 8.264858, 10.630644, 16.067631],
    [53, 8.336814, 10.610023, 15.830899],
    [54, 8.382506, 10.610023, 15.619168],
    [55, 8.417780, 10.599705, 15.394947],
    [56, 8.436510, 10.589379, 15.199700],
    [57, 8.442302, 10.579051, 14.889967],
    [58, 8.432158, 10.568715, 14.693890],
    [59, 8.410817, 10.558376, 14.498613],
    [60, 8.382007, 10.537681, 14.314596],
    [61, 8.343145, 10.516967, 14.132259],
    [62, 8.278637, 10.516967, 13.913662],
    [63, 8.216654, 10.506603, 13.737724],
    [64, 8.086874, 10.496234, 13.443785],
    [65, 8.043736, 10.496234, 13.361016],
    [66, 7.935760, 10.485862, 13.171860],
    [67, 7.760718, 10.475483, 12.914527],
    [68, 7.623944, 10.475483, 12.744855],
    [69, 7.492225, 10.465102, 12.598054],
    [70, 7.344644, 10.454716, 12.451918],
    [71, 7.164230, 10.444326, 12.295277],
    [72, 6.973351, 10.433931, 12.151415],
    [73, 6.783120, 10.402726, 12.024241],
    [74, 6.574781, 10.381905, 11.906287],
    [75, 6.349012, 10.361069, 11.798962],
    [76, 6.086558, 10.329792, 11.697353],
    [77, 5.826365, 10.308926, 11.620868],
    [78, 5.581138, 10.308926, 11.570176],
    [79, 5.343374, 10.298487, 11.537364],
    [80, 5.072518, 10.298487, 11.521136],
    [81, 4.832495, 10.298487, 11.524414],
    [82, 4.614009, 10.298487, 11.541855],
    [83, 4.304583, 10.288048, 11.589682],
    [84, 4.222944, 10.288048, 11.607352],
    [85, 4.041205, 10.298487, 11.655084],
    [86, 3.951253, 10.298487, 11.682187],
    [87, 3.696256, 10.308926, 11.774839],
    [88, 3.609661, 10.308926, 11.811212],
    [89, 3.374635, 10.308926, 11.924354],
    [90, 3.238400, 10.319360, 12.001396],
    [91, 3.105292, 10.319360, 12.083677],
    [92, 2.976019, 10.319360, 12.171863],
    [93, 2.875540, 10.319360, 12.246542],
    [94, 2.753827, 10.319360, 12.344898],
    [95, 2.652013, 10.319360, 12.434496],
    [96, 2.545699, 10.308926, 12.534677],
    [97, 2.480038, 10.308926, 12.601833],
    [98, 2.354272, 10.308926, 12.741342],
    [99, 2.289208, 10.329792, 12.822917],
    [100, 2.232222, 10.340220, 12.897501],
    [101, 2.182564, 10.340220, 12.964527],
    [102, 2.136263, 10.361069, 13.033915],
    [103, 2.089906, 10.361069, 13.103205],
    [104, 2.051651, 10.371490, 13.165311],
    [105, 2.019106, 10.371490, 13.218676],
    [106, 1.987527, 10.371490, 13.272618],
    [107, 1.951919, 10.371490, 13.336256],
    [108, 1.927307, 10.371490, 13.382162],
    [109, 1.895022, 10.381905, 13.447547],
    [110, 1.863108, 10.381905, 13.513089],
    [111, 1.836854, 10.381905, 13.569790],
    [112, 1.791388, 10.381905, 13.674933],
    [113, 1.769139, 10.392318, 13.733324],
    [114, 1.750503, 10.392318, 13.781927],
    [115, 1.730229, 10.402726, 13.841011],
    [116, 1.709898, 10.402726, 13.900052],
    [117, 1.687526, 10.402726, 13.969381],
    [118, 1.666615, 10.402726, 14.039165],
    [119, 1.647174, 10.402726, 14.109374],
    [120, 1.626767, 10.402726, 14.190090],
    [121, 1.611699, 10.413132, 14.261363],
    [122, 1.594949, 10.413132, 14.342886],
    [123, 1.578450, 10.413132, 14.435052],
    [124, 1.567342, 10.413132, 14.507024],
    [125, 1.554193, 10.423533, 14.620687],
    [126, 1.540618, 10.423533, 14.776080],
    [127, 1.535113, 10.423533, 14.890341],
    [128, 1.533412, 10.423533, 15.015121],
    [129, 1.537083, 10.433931, 15.129440],
    [130, 1.545572, 10.433931, 15.274727],
    [131, 1.561427, 10.433931, 15.429844],
    [132, 1.582508, 10.433931, 15.573844],
    [133, 1.610904, 10.444326, 15.716558],
    [134, 1.646569, 10.444326, 15.868290],
    [135, 1.690313, 10.454716, 16.017868],
    [136, 1.762253, 10.465102, 16.223732],
    [137, 1.830139, 10.475483, 16.386629],
    [138, 1.891156, 10.475483, 16.518503],
    [139, 1.977647, 10.475483, 16.684086],
    [140, 2.061933, 10.475483, 16.827162],
    [141, 2.152987, 10.475483, 16.966030],
    [142, 2.268500, 10.465102, 17.125896],
    [143, 2.387224, 10.465102, 17.270227],
    [144, 2.519812, 10.454716, 17.416349],
    [145, 2.669169, 10.454716, 17.560724],
    [146, 2.818836, 10.454716, 17.689350],
    [147, 2.984025, 10.454716, 17.815302],
    [148, 3.138916, 10.454716, 17.920008],
    [149, 3.299232, 10.454716, 18.016201],
    [150, 3.492501, 10.454716, 18.117294],
    [151, 3.769065, 10.454716, 18.236492],
    [152, 3.985603, 10.465102, 18.309309],
    [153, 4.196626, 10.485862, 18.363834],
    [154, 4.399781, 10.485862, 18.405954],
    [155, 4.594790, 10.485862, 18.434616],
    [156, 4.822192, 10.485862, 18.453863],
    [157, 5.019236, 10.496234, 18.456911],
    [158, 5.226393, 10.506603, 18.448036],
    [159, 5.442829, 10.516967, 18.425419],
    [160, 5.667778, 10.516967, 18.388756],
    [161, 5.908995, 10.537681, 18.328884],
    [162, 6.136343, 10.537681, 18.258293],
    [163, 6.367147, 10.548030, 18.166611],
    [164, 6.734711, 10.568715, 17.977280],
    [165, 6.977403, 10.579051, 17.819826],
    [166, 7.203589, 10.610023, 17.639870],
    [167, 7.468131, 10.610023, 17.394379],
    [168, 7.686274, 10.610023, 17.146776],
    [169, 7.889353, 10.620337, 16.861094],
    [170, 8.049699, 10.620337, 16.584728],
    [171, 8.202748, 10.620337, 16.246769],
    [172, 8.356670, 10.599705, 15.754959],
    [173, 8.435511, 10.568715, 15.265859],
    [174, 8.438437, 10.548030, 14.728598],
    [175, 8.363067, 10.506603, 14.206285],
    [176, 8.209455, 10.485862, 13.711517],
    [177, 7.955461, 10.475483, 13.201107],
    [178, 7.679903, 10.475483, 12.811648],
    [179, 7.284064, 10.475483, 12.401190],
    [180, 6.880295, 10.454716, 12.092325],
    [181, 5.705523, 10.433931, 11.607244],
    [182, 5.252936, 10.423533, 11.542618],
    [183, 4.785226, 10.413133, 11.538780],
    [184, 4.331073, 10.392318, 11.594788],
    [185, 3.829324, 10.381905, 11.731894],
    [186, 3.380626, 10.361069, 11.926874],
    [187, 2.990238, 10.361069, 12.166745],
    [188, 2.587251, 10.329792, 12.496656],
    [189, 2.258625, 10.319360, 12.859972],
    [190, 2.070943, 10.308926, 13.123291],
    [191, 1.808329, 10.277606, 13.609670],
    [192, 1.634122, 10.246262, 14.101631],
    [193, 1.513480, 10.173056, 15.105239],
    [194, 1.609874, 10.120717, 15.830251],
    [195, 1.838572, 10.089298, 16.481298],
    [196, 2.191191, 10.057875, 17.074631],
    [197, 2.693043, 10.036922, 17.621723],
    [198, 3.281042, 10.015968, 18.040030],
    [199, 3.892735, 9.984537, 18.312185],
    [200, 4.534757, 9.963583, 18.461079],
    [201, 5.443633, 9.963583, 18.463915],
    [202, 5.691669, 9.963583, 18.423027],
    [203, 6.532745, 9.963583, 18.137867],
    [204, 7.001657, 9.963583, 17.861624],
    [205, 7.322122, 9.984537, 17.608517],
    [206, 7.624618, 9.984537, 17.303907],
    [207, 7.827256, 9.995013, 17.050230],
    [208, 8.016054, 9.995013, 16.760750],
    [209, 8.166505, 10.015968, 16.473038],
    [210, 8.286083, 10.015968, 16.182474],
    [211, 8.376401, 10.015968, 15.892473],
    [212, 8.435678, 10.015968, 15.626667],
    [213, 8.472912, 10.026445, 15.367465],
    [214, 8.491258, 10.026445, 15.085261],
    [215, 8.488346, 10.026445, 14.833888],
    [216, 8.469795, 10.026445, 14.604186],
    [217, 8.415879, 10.026445, 14.273420],
    [218, 8.363358, 10.026445, 14.059805],
    [219, 8.300928, 10.026445, 13.859815],
    [220, 8.226618, 10.026445, 13.663929],
    [221, 8.145262, 10.026445, 13.482281],
    [222, 8.048510, 10.036922, 13.296453],
    [223, 7.940872, 10.036922, 13.116717],
    [224, 7.834938, 10.036922, 12.960732],
    [225, 7.714158, 10.036922, 12.802540],
    [226, 7.605499, 10.047400, 12.674925],
    [227, 7.476209, 10.047400, 12.537685],
    [228, 7.378321, 10.047400, 12.443011],
    [229, 7.268862, 10.047400, 12.345407],
    [230, 7.171846, 10.047400, 12.265465],
    [231, 7.063483, 10.057875, 12.182992],
    [232, 6.951974, 10.068351, 12.104836],
    [233, 6.846389, 10.078825, 12.036643],
    [234, 6.747484, 10.089298, 11.977555],
    [235, 6.572459, 10.089298, 11.882911],
    [236, 6.439947, 10.110244, 11.820181],
    [237, 6.343641, 10.131186, 11.779089],
    [238, 6.226543, 10.152123, 11.733611],
    [239, 6.117953, 10.162591, 11.695368],
    [240, 5.987962, 10.183519, 11.655288],
    [241, 5.856515, 10.204440, 11.620440],
    [242, 5.723966, 10.214899, 11.590229],
    [243, 5.590358, 10.225355, 11.565246],
    [244, 5.476615, 10.235810, 11.548323],
    [245, 5.362396, 10.246262, 11.535195],
    [246, 5.227028, 10.246262, 11.523701],
    [247, 5.091316, 10.246262, 11.517492],
    [248, 4.830117, 10.246262, 11.520439],
    [249, 4.746664, 10.246262, 11.525518],
    [250, 4.559503, 10.246262, 11.544256],
    [251, 4.373625, 10.246262, 11.573069],
    [252, 4.169438, 10.256713, 11.617529],
    [253, 3.958132, 10.256713, 11.676529],
    [254, 3.722338, 10.277606, 11.761580],
    [255, 3.502848, 10.298489, 11.858935],
    [256, 3.281217, 10.308926, 11.975567],
    [257, 3.085491, 10.308926, 12.095509],
    [258, 2.881510, 10.308926, 12.240759],
    [259, 2.712616, 10.319360, 12.380319],
    [260, 2.544823, 10.319360, 12.536880],
    [261, 2.347564, 10.329792, 12.752186],
    [262, 2.230108, 10.329792, 12.898623],
    [263, 2.120727, 10.329792, 13.051188],
    [264, 2.046932, 10.329792, 13.164932],
    [265, 1.972487, 10.329792, 13.290542],
    [266, 1.922573, 10.329792, 13.382122],
    [267, 1.875429, 10.329792, 13.475158],
    [268, 1.844099, 10.329792, 13.541105],
    [269, 1.822571, 10.329792, 13.588607],
    [270, 1.801758, 10.329792, 13.636427], 
]
bottomtData2 = [
    [0, 4.897704, 13.490884, 14.989360],
    [1, 4.866502, 13.489817, 14.985710],
    [2, 4.835277, 13.488467, 14.982368],
    [3, 4.814528, 13.487411, 14.979584],
    [4, 4.783412, 13.485590, 14.975500],
    [5, 4.741866, 13.482723, 14.970800],
    [6, 4.638179, 13.473364, 14.959072],
    [7, 4.534976, 13.460878, 14.945984],
    [8, 4.421803, 13.443548, 14.932838],
    [9, 4.269040, 13.413877, 14.910646],
    [10, 4.077871, 13.366381, 14.881658],
    [11, 3.870373, 13.301170, 14.848133],
    [12, 3.677311, 13.226884, 14.814092],
    [13, 3.488723, 13.140984, 14.782959],
    [14, 3.332919, 13.059068, 14.755478],
    [15, 3.190419, 12.974699, 14.729028],
    [16, 3.077090, 12.901095, 14.712057],
    [17, 2.958319, 12.816898, 14.694272],
    [18, 2.860344, 12.740768, 14.673035],
    [19, 2.764217, 12.661089, 14.658345],
    [20, 2.678642, 12.585016, 14.645268],
    [21, 2.595594, 12.506128, 14.632578],
    [22, 2.523513, 12.432041, 14.613956],
    [23, 2.397423, 12.293218, 14.594301],
    [24, 2.298128, 12.172405, 14.578823],
    [25, 2.211702, 12.055675, 14.556779],
    [26, 2.123197, 11.926588, 14.542711],
    [27, 2.044450, 11.802583, 14.539279],
    [28, 1.967320, 11.666197, 14.527256],
    [29, 1.878456, 11.488635, 14.513403],
    [30, 1.807533, 11.325647, 14.502348],
    [31, 1.741490, 11.149324, 14.492053],
    [32, 1.687835, 10.979712, 14.483688],
    [33, 1.645203, 10.817741, 14.477043],
    [34, 1.594092, 10.561034, 14.469076],
    [35, 1.573035, 10.394992, 14.455258],
    [36, 1.557605, 10.217586, 14.452806],
    [37, 1.549989, 10.071041, 14.462201],
    [38, 1.551713, 9.924372, 14.451869],
    [39, 1.556636, 9.798751, 14.452652],
    [40, 1.569063, 9.642110, 14.454627],
    [41, 1.588436, 9.486197, 14.457706],
    [42, 1.610815, 9.351899, 14.461264],
    [43, 1.640679, 9.208380, 14.466011],
    [44, 1.668303, 9.096581, 14.470402],
    [45, 1.697995, 8.985767, 14.485272],
    [46, 1.743434, 8.836459, 14.512352],
    [47, 1.771986, 8.757774, 14.516627],
    [48, 1.804909, 8.670110, 14.531354],
    [49, 1.820928, 8.631454, 14.533703],
    [50, 1.871724, 8.516695, 14.541154],
    [51, 1.871724, 8.516695, 14.541154],
    [52, 2.084893, 8.113459, 14.625885],
    [53, 2.158987, 8.000300, 14.644055],
    [54, 2.236485, 7.890185, 14.670593],
    [55, 2.319323, 7.783277, 14.688621],
    [56, 2.412386, 7.671919, 14.715155],
    [57, 2.517511, 7.557169, 14.741793],
    [58, 2.620986, 7.454527, 14.759768],
    [59, 2.728744, 7.356375, 14.777531],
    [60, 2.856982, 7.249919, 14.796580],
    [61, 2.990813, 7.149799, 14.809284],
    [62, 3.154221, 7.039453, 14.841542],
    [63, 3.315693, 6.943778, 14.860494],
    [64, 3.605482, 6.800035, 14.888707],
    [65, 3.789184, 6.725534, 14.907023],
    [66, 3.897564, 6.687250, 14.915345],
    [67, 4.158101, 6.611166, 14.937892],
    [68, 4.352003, 6.568577, 14.952196],
    [69, 4.537553, 6.538509, 14.967278],
    [70, 4.714173, 6.519376, 14.979775],
    [71, 4.870647, 6.510010, 14.990848],
    [72, 4.939203, 6.508133, 14.995698],
    [73, 4.939203, 6.508133, 14.995698],
    [74, 4.939203, 6.508133, 14.995698],
    [75, 4.939203, 6.508133, 14.995698],
    [76, 4.939216, 6.508133, 14.995516],
    [77, 4.939216, 6.508133, 14.995516],
    [78, 4.939216, 6.508133, 14.995516],
    [79, 4.939216, 6.508133, 14.995516],
    [80, 4.939216, 6.508133, 14.995516],
    [81, 4.939216, 6.508133, 14.995516],
    [82, 4.939216, 6.508133, 14.995516],
    [83, 4.939216, 6.508133, 14.995516],
    [84, 4.939216, 6.508133, 14.995516],
    [85, 4.939216, 6.508133, 14.995516],
    [86, 4.939216, 6.508133, 14.995516],
    [87, 4.939216, 6.508133, 14.995516],
    [88, 4.939216, 6.508133, 14.995516],
    [89, 4.939216, 6.508133, 14.995516],
    [90, 4.939216, 6.508133, 14.995516],
    [91, 4.939216, 6.508133, 14.995516],
    [92, 4.939216, 6.508133, 14.995516],
    [93, 4.939216, 6.508133, 14.995516],
    [94, 4.939216, 6.508133, 14.995516],
    [95, 4.939216, 6.508133, 14.995516],
    [96, 4.939216, 6.508133, 14.995516],
    [97, 4.939216, 6.508133, 14.995516],
    [98, 4.939203, 6.508133, 14.995698],
    [99, 4.939178, 6.508133, 14.996063],
    [100, 4.939145, 6.508133, 14.996611],
    [101, 4.939145, 6.508133, 14.996611],
    [102, 4.939126, 6.508133, 14.996976],
    [103, 4.939109, 6.508133, 14.997341],
    [104, 4.939109, 6.508133, 14.997341],
    [105, 4.939101, 6.508133, 14.997524],
]

dataSets = [leftData1, leftData2, bottomtData1, bottomtData2]
dataSetsName = ["leftData1", "leftData2", "bottomtData1", "bottomtData2"]

index = 1
for data in dataSets:
    x_list = []
    y_list_x = []
    y_list_y = []
    y_list_z = []
    for point in data:
        x_list.append(point[0])
        y_list_x.append(point[1])
        y_list_y.append(point[2])
        y_list_z.append(point[3])

    plt.subplot(2, 2, index)
    plt.plot(x_list, y_list_x)  # X = BLUE
    plt.plot(x_list, y_list_y)  # Y = ORANGE
    plt.plot(x_list, y_list_z)  # Z = GREEN
    plt.title(dataSetsName[index - 1])
    plt.grid(color='black', linestyle='-', linewidth=0.3)
    plt.axhline(y=0, color="black")
    plt.axvline(x=0, color="black")
    plt.locator_params(axis='y', nbins=20)
    plt.locator_params(axis='x', nbins=20)
    index += 1

plt.show()