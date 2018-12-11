function [outputImg, outputCentroids] = find_object_centroids(img)
    grayscale_img = rgb2gray(img);
    threshold = graythresh(grayscale_img);
    only_background_mask = imbinarize(grayscale_img, threshold);
    not_background_mask = ~only_background_mask;
    no_background_img = img.*repmat(uint8(not_background_mask),[1,1,3]);

    only_background_mask = imfill(only_background_mask, 'holes');
    background_regions = regionprops(only_background_mask,grayscale_img,{'Area', 'Centroid', 'PixelIdxList'});

    [max_area, max_id] = max([background_regions.Area]);
    max_region_pixels = background_regions(max_id).PixelIdxList;

    table_mask = zeros(size(only_background_mask));
    table_mask(max_region_pixels) = 1;
    table_mask = imerode(table_mask, strel('cube',10));
    only_table_img = no_background_img.*repmat(uint8(table_mask),[1,1,3]);
    no_table_background_mask = table_mask & not_background_mask;

    objects = regionprops(no_table_background_mask,grayscale_img,{'Area', 'Centroid'});
    allCentroids = arrayfun(@(n) n > 60, [objects.Area]);
    validCentroidIdx = find(allCentroids == 1);
    numValidCentroids = length(validCentroidIdx);
    unformattedCentroids = [objects(validCentroidIdx).Centroid];
    finalCentroids = transpose(reshape(unformattedCentroids, [2, numValidCentroids]));

    filteredImg = img;
    for i=1:numValidCentroids
        currX = finalCentroids(i, 1);
        currY = finalCentroids(i, 2);
        filteredImg = insertShape(filteredImg, 'circle', [currX currY 20], 'LineWidth', 10, 'Color', 'green');
    end
    
    outputImg = filteredImg;
    outputCentroids = finalCentroids;
end
