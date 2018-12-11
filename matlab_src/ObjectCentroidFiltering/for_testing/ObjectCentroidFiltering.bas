Dim MCLUtil As Object
Dim bModuleInitialized As Boolean
Dim Class1 As Object 

Private Sub InitModule()
    If Not bModuleInitialized Then
        On Error GoTo Handle_Error
        If MCLUtil Is Nothing Then
            Set MCLUtil = CreateObject("MWComUtil.MWUtil9.5")
        End If
        Call MCLUtil.MWInitApplication(Application)
        
        bModuleInitialized = True
        Exit Sub
Handle_Error:
        bModuleInitialized = False
    End If
End Sub

Function find_object_centroids(Optional img As Variant) As Variant

    Dim outputImg, outputCentroids As Variant

    On Error GoTo Handle_Error

    Call InitModule()

    If Class1 Is Nothing Then
        Set Class1 = CreateObject("ObjectCentroidFiltering.Class1.1_0")
    End If

    ' By default, MATLAB Excel Add-in returns just 1 output for M functions 
    ' which have more than one output.    

    Call Class1.find_object_centroids(2, outputImg, outputCentroids, img)
    find_object_centroids = outputImg

    ' If you want to use all the return values, you can use the following 
    ' code as a guideline. To use this form, call the function from Excel cell,
    ' highlight the cells which will receive the outputs and hit Ctrl+Shift+Enter.
    '
    ' Call Class1.find_object_centroids(2, outputImg, outputCentroids, img)
    ' find_object_centroids = Array(outputImg, outputCentroids)

    Exit Function
Handle_Error:
    find_object_centroids = "Error in " & Err.Source & ": " & Err.Description
End Function

