 
// Verificar CLA
// // Verificar FILE == WAV
// // Verificar Output.wav
// CLA = ./filter [flag] input output


if(argv[2] == "-g"){

} if(argv[2] == "-r"){
    
} if(argv[2] == "-b"){

} if(argv[2] == "-e"){
    
} else{
    printf("Please uses a flag as -g, -r, -b, -e. \n");
}

// -g Gray filter
// Taking avarage of RGB, Applying as Gray in the document

// -r Reflection
// Invert locations, a, b, c, d => d, c, b, a

// -b Blur
// Avarege of 3x3 bloc of newar pixels == pixel in the center

// -e Edge
// Sobel operator