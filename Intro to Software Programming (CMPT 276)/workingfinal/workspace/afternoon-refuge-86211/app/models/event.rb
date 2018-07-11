class Event < ActiveRecord::Base
  geocoded_by:location 
  after_validation :geocode, if: ->(obj){ obj.location.present? and obj.location_changed? }
  after_validation :lat_changed?
  private

# This is used to make sure that our address is actually parsed properly and we
# get a valuable lat/long
def lat_changed?
    if (self.location_changed?)
        if !(self.latitude_changed?)
            self.errors.add(:location, "is not valid")
            return false
        end
    end
    return true
end
  
    
end
